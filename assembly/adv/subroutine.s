section .data
section .text

global main

add:
    PUSH ebp
    MOV ebp,esp
    MOV eax,[ebp + 8]
    MOV ebx,[ebp + 12]
    ADD eax,ebx
    MOV ebx,eax
    POP ebp
    RET

main:
    PUSH 10
    PUSH 5
    CALL add

    MOV eax,1
    INT 80h
     
    
