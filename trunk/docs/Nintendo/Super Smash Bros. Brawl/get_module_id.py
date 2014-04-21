import glob
import os

results = {}

for fname in glob.glob("*.rel"):
    f = open(fname, "rb")
    f.read(3)
    byte = f.read(1)
    results[ord(byte)] = fname
    f.close()

o = open("results.txt", "w")
for k,v in sorted(results.items()):
    o.write("%02X %s\n" % (k,v))

o.close()

