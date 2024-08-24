.global _start
.intel_syntax noprefix

_start: 
    #writing hello world
    mov rax,1
    mov rdi,1  #stdout file descriptor = 1 
    lea rsi,[buffer]
    mov rdx,12
    syscall

    //exiting the program
    mov rax,60
    mov rdi,55 
    syscall 

buffer:
    .asciz "Hello World\n"
