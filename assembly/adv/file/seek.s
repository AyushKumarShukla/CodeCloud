extern printf
extern exit

section .data
    path DD "/home/coder/remoterepo/assembly/adv/file/text"
    fmt DD "%s",10,0

section .bss
    buffer: resb 24

section .text

global main

main:
    MOV eax, 5 ; sys_open 
    MOV ecx, 0 ; O_RDONLY -> Open for Read Only
    MOV ebx, path
    INT 80h
    
    MOV ebx,eax
    MOV eax, 19 ; sys_lseek
    MOV ecx, 122
    MOV edx, 0
    INT 80h

    MOV eax, 3
    MOV ecx, buffer
    MOV edx, 6
    INT 80h

    MOV eax, 1
    MOV ebx, [buffer]
    INT 80h

