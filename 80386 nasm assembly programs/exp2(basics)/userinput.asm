section .data
	msg1 db 'Enter your name: ',10
	msg1len equ $-msg1
	msg db 'Enter your age: ',10
	msglen equ $-msg
	msg2 db 'STUDENT INFORMATION: ',10
	msg2len equ $-msg2
section .bss
	name resb 20
	age resb 20
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
	mov ecx, name
	mov edx, 20
	int 80h
	
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, msglen
	int 80h
	
	mov eax, 3
	mov ebx, 2
	mov ecx, age
	mov edx, 20
	int 80h
	
	mov eax, 4
	mov ebx, 1
	mov ecx, msg2
	mov edx, msg2len
	int 80h
	
	mov eax, 4
	mov ebx, 1
	mov ecx, name
	mov edx, 20
	int 80h
	
	mov eax, 4
	mov ebx, 1
	mov ecx, age
	mov edx, 20
	int 80h
	
	mov eax, 1
	mov ebx, 0
	int 80h
	
