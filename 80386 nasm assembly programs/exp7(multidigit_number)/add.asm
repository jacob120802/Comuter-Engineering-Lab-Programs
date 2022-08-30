section .data
	msg db'The Sum is: '
	len equ $-msg
	msg1 db 'Enter your first number:'
	msg1len equ $-msg1	
	msg2 db 'Enter your second number:'	
	msg2len equ $-msg2
	smsg db' ',10
	slen equ $-smsg
	
section .bss
	sum resb 4
	num1 resb 4
	num2 resb 4
	
section .text

global _start
_start:
	mov eax, 4	
	mov ebx, 1	
	mov ecx, msg1
	mov edx, msg1len
	int 80h	
	
	mov eax, 3	
	mov ebx, 2	
	mov ecx, num1
	mov edx, 5
	int 80h		
	
	mov eax, 4	
	mov ebx, 1
	mov ecx, msg2
	mov edx, msg2len
	int 80h
	
	mov eax, 3
	mov ebx, 2
	mov ecx, num2
	mov edx, 5
	int 80h	
	
	mov esi, 3
	mov ecx, 4
	clc
	
	add_loop:
		mov al, [num1 + esi] 
		adc al, [num2 + esi]
		aaa
		pushf
		or al, 30h
		popf
	
		mov [sum + esi], al
		dec esi
		loop add_loop
	
	mov eax, 4	
	mov ebx, 1
	mov ecx, msg
	mov edx, len
	int 80h
	
	mov eax, 4	
	mov ebx, 1
	mov ecx, sum
	mov edx, 4
	int 80h
	
	mov eax, 4	
	mov ebx, 1
	mov ecx, smsg
	mov edx, slen
	int 80h
	
	mov eax, 1
	mov ebx, 0
	int 80h

