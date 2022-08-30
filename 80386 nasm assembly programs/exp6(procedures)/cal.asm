section .data
	m1 db 'Enter number 1: '
	m1Len equ $-m1
	m3 db 'Enter number 2: '
	m3Len equ $-m3
	msg db  "Sum: "
	len equ $ - msg
	msg2 db  "Difference: "
	len2 equ $ - msg2
	msg3 db  "Multiplication: "
	len3 equ $ - msg3
	msg4 db  "	Quotient: "
	len4 equ $ - msg4
	msg5 db "	Remainder: "
	len5 equ $ - msg5
	newline db "",10
	newlinelen equ $- newline
	msg6 db "Division: ",10
	len6 equ $ - msg6

%macro readsystem 2
	mov eax, 3
	mov ebx, 2
	mov ecx, %1
	mov edx, %2
	int 80h
%endmacro

%macro writesystem 2
	mov eax, 4
	mov ebx, 1
	mov ecx, %1
	mov edx, %2
	int 80h
%endmacro

section .bss
	x RESB 2
	y RESB 2
	sum RESB 5
	diff RESB 5
	mult RESB 5
	divis RESB 5
	remain RESB 5

section .text
global _start

_start:
	writesystem m1,m1Len 
	readsystem x,2  
 	writesystem m3,m3Len 
	readsystem y,2  ;
    	
	;For addition
    	call addition
	mov [sum], eax
	int 80h
	writesystem msg, len
	writesystem sum, 1
	writesystem newline, newlinelen

	;For subtraction
    	call subtraction
	mov [diff], eax
	int 80h
	writesystem msg2, len2
	writesystem diff, 1
	writesystem newline, newlinelen

	;For Multiplication
    	call multi
    	mov [mult], eax
    	int 80h
	writesystem msg3, len3
	writesystem mult, 1
	writesystem newline, newlinelen

	;For Division
	call divi
	writesystem msg6, len6
	writesystem msg4, len4
	writesystem divis, 1
	writesystem newline, newlinelen
	writesystem msg5, len5
	writesystem remain, 1
	writesystem newline, newlinelen
	
	mov eax, 1
	mov ebx, 0
    	int 80h
	
addition:
	mov eax, [x]
    	sub eax, '0'
    	mov ebx, [y]
    	sub ebx, '0'
	add eax, ebx
    	add eax, '0'
ret

subtraction:
	mov eax, [x]
    	sub eax, '0'
    	mov ebx, [y]
    	sub ebx, '0'
	sub eax, ebx
    	add eax, '0'
ret

multi:
	mov eax, [x]
    	sub eax, '0'
    	mov ebx, [y]
    	sub ebx, '0'
    	mul ebx
    	add eax, '0'
ret

divi:
	mov al, [x]
    	sub al, '0'
    	mov bl, [y]
    	sub bl, '0'
	div bl
    	add al, '0'
	add ah, '0'
	mov [remain], ah
	mov [divis], al
ret
