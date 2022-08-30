 section .data
    msg         db      '',10
    lmsg        equ     $ - msg
    msg1        db      'Enter Number 1: '
    lmsg1       equ     $ - msg1
    msg2        db      'Enter Number 2: '
    lmsg2       equ     $ - msg2
    msg3        db      'PERFORMING ARTHEMATIC OPERATIONS...',10
    lmsg3       equ     $ - msg3
    msg4        db      '	Addition Result: '
    lmsg4       equ     $ - msg4
    msg5        db      '	Subtraction Result: '
    lmsg5       equ     $ - msg5
    msg6        db      '	Multiplication Result: '
    lmsg6       equ     $ - msg6
    msg7        db      '	Division Result: '
    lmsg7       equ     $ - msg7
    msg8        db      '	Division Remainder: '
    lmsg8	equ     $ - msg8    
    
section .bss
    ; Spaces reserved for storing the values ​​provided by the user.
    num1       resb    2
    num2       resb    2
    result     resb    2
    remainder  resb    2

section .text

global _start
_start:

    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, lmsg1
    int 80h

    mov eax, 3
    mov ebx, 0
    mov ecx, num1
    mov edx, 2
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, lmsg2
    int 80h

    mov eax, 3
    mov ebx, 0
    mov ecx, num2
    mov edx, 2
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, msg3
    mov edx, lmsg3
    int 80h
    
    ;addition
    mov eax, 4
    mov ebx, 1
    mov ecx, msg4
    mov edx, lmsg4
    int 80h
    ; We keep the numbers in the registers al and bl
    mov al, [num1]
    mov bl, [num2]
    ; Convert from ascii to decimal
    sub al, '0'
    sub bl, '0'
    ; Add
    add al, bl
    ; Conversion from decimal to ascii
    add al, '0'
    ; We move the result
    mov [result], al
    ; Print on screen the result
    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 2
    int 80h

    ;newline
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, lmsg
    int 80h

    ;substraction
    mov eax, 4
    mov ebx, 1
    mov ecx, msg5
    mov edx, lmsg5
    int 80h
    ; We keep the numbers in the registers al and bl
    mov al, [num1]
    mov bl, [num2]
    ; Convert from ascii to decimal
    sub al, '0'
    sub bl, '0'
    ; Subtract
    sub al, bl
    ; Conversion from decimal to ascii
    add al, '0'
    ; We move the result
    mov [result], al
    ; Print on screen the result
    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 1
    int 80h
    
    ;newline
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, lmsg
    int 80h

    ;multiplication
    mov eax, 4
    mov ebx, 1
    mov ecx, msg6
    mov edx, lmsg6
    int 80h
    ; We store the numbers in registers al and bl
    mov al, [num1]
    mov bl, [num2]
    ; Convert from ascii to decimal
    sub al, '0'
    sub bl, '0'
    ; Multiply. AX = AL x BL
    mul bl
    ; Conversion from decimal to ascii
    add ax, '0'
    ; We move the result
    mov [result], ax
    ; Print on screen the result
    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 2
    int 80h
    
    ;newline
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, lmsg
    int 80h
    
    ;division
    mov eax, 4
    mov ebx, 1
    mov ecx, msg7
    mov edx, lmsg7
    int 80h
    ; We store the numbers in registers al and bl
    mov al, [num1]
    mov bl, [num2]
    ; Convert from ascii to decimal
    sub al, '0'
    sub bl, '0'
    ; Division. AH= AL / BL
    div bl
    ; Conversion from decimal to ascii
    add al, '0'
    add ah, '0'
    ; We move the result
    mov [result],al
    mov [remainder], ah
    ; Print on screen the result
    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 2
    int 80h
    
    ; Print on screen the result
    mov eax, 4
    mov ebx, 1
    mov ecx, msg8
    mov edx, lmsg8
    int 80h
    
    ; Print on screen the result
    mov eax, 4
    mov ebx, 1
    mov ecx, remainder
    mov edx, 2
    int 80h
    
    ;newline
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, lmsg
    int 80h

    ; End the program
    mov eax, 1
    mov ebx, 0
    int 80h
