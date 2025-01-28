section .data
    num1 DD 1.12
    num2 DD 3.66

section .text
global _start

_start:
    MOVSS xmm0,[num1]
    MOVSS xmm1,[num2]
    ADDSS xmm0,xmm1
    MOV eax,1
    INT 80h
