section .data
    list DB 5,6,7,8,9

section .text
global _start

_start:
    MOV al,0 ;accumulator for storing sum
    MOV ebx,0  ;index counter
    MOV cl,0  ;stores current index valeie

loop:
    MOV cl, [list + ebx]
    ADD al,cl
    INC ebx
    CMP ebx,5
    JE exit
    JMP loop

exit:
    MOV eax,1
    MOV ebx,1
    INT 80h
    
