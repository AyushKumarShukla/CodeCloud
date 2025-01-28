extern printf
extern exit

section .data
    msg1 DD "This is a message",0
    msg2 DD "This is another message",0
    fmt DD "Hello World %s %s",10,0
section .text
global main

main:
    PUSH msg2
    PUSH msg1
    PUSH fmt
    CALL printf
    PUSH 55
    CALL exit
