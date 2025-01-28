section .bss
    block RESB 3

section .data
    block2 DB 5 DUP(5)

section .text
global _start

_start:
    MOV bl,4
    MOV bh,1
    MOV [block],bl
    MOV [block+1],bl
    MOV [block+2],bl

    MOV [block2 ],bh
    MOV [block2 + 1],bh
    MOV [block2 + 2],bh
    MOV [block2 + 3],bh
    MOV [block2 + 4],bh
    MOV [block2 + 5],bh
    
    MOV eax,1
    INT 80h

