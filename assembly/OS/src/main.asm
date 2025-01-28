org 0x7C00
bits 16
%define ENDL 0x0D,0x0A ; newline + return character

start:
    JMP main

puts:
    ; save all registers in stack before modification
    PUSH si 
    PUSH ax
    PUSH bx

.loop:
    lodsb ; read byte from source index (si)
    OR al,al ; if byte == 0 (NULL) we are done
    JZ .done

    MOV AH, 0x0E ; bios interrupt code for video writing
    MOV BH, 0   ; set page number to 0
    INT 0x10 ; interrupt code

    JMP .loop ; loop and call interrupt until NULL is encountered

.done:
    ; retain all registers and return to main
    POP bx
    POP ax
    POP si
    RET

main:
    ; setup data segments
    MOV ax,0
    MOV DS,ax
    MOV ES,ax

    ;setup stack
    MOV ss, ax
    MOV sp, 0x7C00 ; grows downwards

    ;call puts
    MOV si, msg ; set address of msg to SI
    CALL puts
    HLT

.halt:
    JMP .halt

msg: db "Youve Broken In Dear WhiteRaven",ENDL,0

times 510-($-$$) DB 0
DW 0AA55h
