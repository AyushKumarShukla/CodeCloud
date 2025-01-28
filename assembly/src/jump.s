section .data
    string1 DB "eax is greater than ebx",0
    string2 DB "eax is lesser than ebx",0
section .text
global _start

_start:
    MOV eax, 10
    MOV ebx, 8
    CMP eax,ebx
    JL lesser
    JMP not_lesser

lesser:
    MOV cl, [string2]
    INT 80h
not_lesser:
    MOV cl, [string1]
    INT 80h
