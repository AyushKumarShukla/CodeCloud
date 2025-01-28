section .data
    string DW "AB",0

section .text
global _start

_start:
    MOV bl,[string]
    MOV eax, 1
    INT 80h

