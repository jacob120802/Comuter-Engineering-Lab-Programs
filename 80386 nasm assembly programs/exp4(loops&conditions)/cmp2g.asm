section .data
	msg1 db 'Enter your first number:'
	msg1len equ $-msg1	
	msg2 db 'Enter your second number:'	
	msg2len equ $-msg2
	msg3 db 'Greater of 2 number is:'	
	msg3len equ $-msg3
	msg  db '',10
	msglen equ $-msg
section .bss
	num1 resb 9
	num2 resb 9
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
	mov edx, 9
	int 80h		
	
	mov eax, 4	
	mov ebx, 1
	mov ecx, msg2
	mov edx, msg2len
	int 80h
	
	mov eax, 3	
	mov ebx, 2
	mov ecx, num2
	mov edx, 9
	int 80h	
	
	mov eax, 4	
	mov ebx, 1
	mov ecx, msg3
	mov edx, msg3len
	int 80h	
	
	mov eax, [num1]
	mov ebx, [num2]
	cmp eax, ebx
	
	jg l1
	jl l2
	
	l1:
		mov eax, 4	
		mov ebx, 1
		mov ecx, num1
		mov edx, 9
		int 80h	
		jmp exit
	l2:
		mov eax, 4	
		mov ebx, 1
		mov ecx, num2
		mov edx, 9
		int 80h	
	exit:	
		mov eax,1	
		mov ebx,0
		int 80h
	
	       
	
