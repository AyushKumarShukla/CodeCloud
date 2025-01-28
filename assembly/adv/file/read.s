extern printf
extern exit

section .data
    path DD "/home/coder/remoterepo/assembly/adv/file/text"
    fmt DD "%s",10,0
section .bss
    buffer: resb 1024

section .text

global main

main:
    MOV eax, 5 ; sys_open 
    MOV ecx, 0 ; O_RDONLY -> Open for Read Only
    MOV ebx, path
    INT 80h
    
    MOV ebx, eax
    MOV eax, 3
    MOV ecx, buffer
    MOV edx, 1024
    INT 80h
    
    PUSH buffer
    PUSH fmt
    CALL printf
    PUSH 1
    CALL exit



