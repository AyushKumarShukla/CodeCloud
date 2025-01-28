section .data
    val DB 8
    val2 DB 1
section .text
    global _start

_start:
    MOV eax,1
    MOV ebx,[val]
    INT 80h
