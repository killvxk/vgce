#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <Windows.h>
#include "easyzlib.h"

using namespace std;

typedef unsigned char uchar;

#pragma pack(1)
struct indexEntry
{
  uchar nArchiveId;
  uchar flags;
  unsigned offset;
  unsigned size;
  unsigned decompressedSize;
};
#pragma pack()

string getStr(istream &is)
{
  uchar size;
  is.read((char*)&size, sizeof(size));

  char tmp[256];
  memset(tmp, 0, sizeof(tmp));
  is.read(tmp, size*sizeof(char));
  return string(tmp);
}

int main()
{
  vector<indexEntry> index;
  map<int,string> strings;
  vector<ifstream> archives;
  unsigned n;

  // Read index data
  ifstream f_index("index.bin", ios::binary);
  f_index.read((char*)&n, sizeof(n));

  cerr << ( f_index ? "f_index opened" : "f_index failed" ) << endl;

  // index entries
  while ( n-- )
  {
    indexEntry tmp;
    f_index.read((char*)&tmp, sizeof(tmp));
    index.emplace_back(tmp);
  }

  cerr << "Read index entries" << endl;
  
  // index archives
  f_index.read((char*)&n, sizeof(n));
  while ( n-- )
    archives.emplace_back( ifstream(getStr(f_index), ios::binary) );

  f_index.close();
  cerr << "archives opened" << endl;

  // Read strings
  ifstream f_strings("1s", ios::binary);
  f_strings.read((char*)&n, sizeof(n));

  cerr << ( f_strings ? "f_strings opened" : "f_strings failed" ) << endl;

  while ( n-- )
  {
    string s = getStr(f_strings);
    unsigned id;
    f_strings.read((char*)&id, sizeof(id));
    
    size_t t = s.find_last_of('_');
    if ( t != string::npos )
      s[t] = '.';

    for ( char & c : s )
      if ( c == '_' ) c = '/';

    strings[id] = s;
  }
  f_strings.close();
  cerr << "Strings read" << endl;

  // Splice archive data
  char *buff = (char*)malloc(4096);
  char *buffOut = (char*)malloc(8192);
  for ( unsigned i = 0; i < index.size(); ++i )
  {
    indexEntry const &e = index[i];
    if ( e.nArchiveId >= archives.size() )
      continue;

    ifstream &in = archives[e.nArchiveId];

    buff = (char*)realloc(buff, e.size );
    buffOut = (char*)realloc(buffOut, e.decompressedSize);
    
    in.seekg(e.offset);
    in.read(buff, e.size);
    
    string path = string("extracted/") + strings[i];
    
    // Create directory tree
    size_t n = 0;
    while ( n = path.find_first_of('/',n+1), n != string::npos )
      CreateDirectory(path.substr(0, n).c_str(), NULL);
    
    char *pResult = buff;
    long dstLen = e.decompressedSize;
    if ( e.flags == 6 )
    {
      ezuncompress((uchar*)buffOut, &dstLen, (uchar*)buff, e.size);

      if ( dstLen != e.decompressedSize )
        cerr << "Decompressed size mismatch! " << dstLen << " != " << e.decompressedSize << endl;

      pResult = buffOut;
    }

    ofstream out(path, ios::binary);
    if ( !out )
      cerr << "Unable to open " << path << endl;
    out.write(pResult, dstLen);
  }

  cerr << "Finished!" << endl;
  cin.ignore(10000,'\n');
}
