section .data
    path DB "/home/coder/remoterepo/assembly/adv/file/new.txt",0
    msg DB "THE DREAM IS MINE KRAKEN",0AH,0DH
section .text

global main

main:

    MOV eax, 5
    MOV ebx, path
    MOV ecx, 101o
    MOV edx, 600o
    INT 80H
    
    MOV ebx, eax
    MOV eax, 4
    MOV ecx, msg
    MOV edx, 27
    INT 80H

    MOV eax, 1
    MOV ebx, 0
    INT 80H




