section .data
    x DD 1.56
    y DD 0.5
section .text
global _start

_start:
    MOVSS xmm0, [x]
    MOVSS xmm1, [y]
    UCOMISS xmm0, xmm1
    MOV eax, 01
    MOV ebx, 02
    INT 80h

