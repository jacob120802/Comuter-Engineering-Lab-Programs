 %macro write_sys_call 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro

%macro read_sys_call 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro

%macro addition 3
    write_sys_call msg4, lmsg4
    ; We keep the numbers in the registers al and bl
    mov al, %1
    mov bl, %2
    ; Convert from ascii to decimal
    sub al, '0'
    sub bl, '0'
    ; Add
    add al, bl
    ; Conversion from decimal to ascii
    add al, '0'
    ; We move the result
    mov %3, al
    ; Print on screen the result
    write_sys_call %3, 2
%endmacro

%macro substraction 3
    write_sys_call msg5, lmsg5
    ; We keep the numbers in the registers al and bl
    mov al, %1
    mov bl, %2
    ; Convert from ascii to decimal
    sub al, '0'
    sub bl, '0'
    ; Subtract
    sub al, bl
    ; Conversion from decimal to ascii
    add al, '0'
    ; We move the result
    mov %3, al
%endmacro

%macro multiplication 3
    write_sys_call msg6, lmsg6
    ; We store the numbers in registers al and bl
    mov al, %1
    mov bl, %2
    ; Convert from ascii to decimal
    sub al, '0'
    sub bl, '0'
    ; Multiply. AX = AL x BL
    mul bl
    ; Conversion from decimal to ascii
    add ax, '0'
    ; We move the result
    mov %3, ax
%endmacro

%macro division 4
    write_sys_call msg7, lmsg7
    ; We store the numbers in registers al and bl
    mov al, %1
    mov bl, %2
    ; Convert from ascii to decimal
    sub al, '0'
    sub bl, '0'
    ; Division. Ax= AL / BL,  AH-Remainder
    div bl
    ; Conversion from decimal to ascii
    add al, '0'
    add ah, '0'
    ; We move the result
    mov %3,al
    mov %4, ah
%endmacro

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

    write_sys_call msg1, lmsg1
    read_sys_call num1, 2

    write_sys_call msg2, lmsg2
    read_sys_call num2, 2
    
    write_sys_call msg3, lmsg3
    
    ;addition
    addition [num1], [num2], [result]
    ; Print on screen the result
    write_sys_call result, 2

    ;newline
    write_sys_call msg, lmsg

    ;substraction
    substraction [num1], [num2], [result]
    ; Print on screen the result
    write_sys_call result, 2
    
    ;newline
    write_sys_call msg, lmsg

    ;multiplication
    multiplication [num1], [num2], [result]
    ; Print on screen the result
    write_sys_call result, 2
    
    ;newline
    write_sys_call msg, lmsg
    
    ;division
    division [num1], [num2], [result],  [remainder]
    ; Print on screen the result
   write_sys_call result, 2
   write_sys_call msg8, lmsg8
    ; Print on screen the remainder
    write_sys_call remainder, 2
    
    ;newline
    write_sys_call msg, lmsg

    ; End the program
    mov eax, 1
    mov ebx, 0
    int 80h
