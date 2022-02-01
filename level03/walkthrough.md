# A little xor encryption

see source.c

## Analysis

Disassembling was the 'hard' part, since there is weird things with pointer in the function test but when you disassemble 'decrypt' you can clearly see a encrypted key with a small xor loop. Since we have to find a number between 0 and 21 to decrypt the key to 'Congratulations', we just did a small main (see resources/decrypt.c) that test the 21 solutions. Then we just need to substract this number to 0x1337d00d and we get a shell of level04 !

```
(python -c "print(str(0x1337d00d - 18))" ; echo "cat /home/users/level04/.pass") | ./level03 
```
