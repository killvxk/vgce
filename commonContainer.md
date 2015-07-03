# Games Seen #

  * Okami


# File Format #

Uses an alignment directive? Yet to be examined.

```
    0x00    u32                     Num Entries
    0x04    u32[Num Entries]        Pointer to entry
            char[4][Num Entries]    File Type (extension)
```

For each file; Pointer to entry - 0x20 for file name and other information.