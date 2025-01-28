extern add
extern exit

section .data
section .text
global main

main:
    PUSH 5
    PUSH 10
    CALL add
    PUSH eax
    CALL exit

