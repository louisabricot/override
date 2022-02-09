# Hardcoded password

see source.c

## Analysis

The program prompts for a password and compare the input with a hardcoded value.
If the input matches that hardcoded value of 5276, the program calls bin/sh as level01.

```
(echo 5276; sleep 0.2; echo "cat /home/users/level01/.pass") | ./level00
```
