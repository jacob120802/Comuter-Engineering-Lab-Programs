SYSTEM_WRITE equ 4
SYSTEM_READ equ 3
SYSTEM_EXIT equ 1
STDOUT equ 1
STDIN equ 2

section .data
	msg1 db 'Enter your first number:'
	msg1len equ $-msg1	
	msg2 db 'Enter your second number:'	
	msg2len equ $-msg2	
	msg3 db 'After Addition of the 2 input numbers result is:',10	
	msg3len equ $-msg3
	msg  db '',10
	msglen equ $-msg
	
section .bss
	num1 resb 9
	num2 resb 9
	num resb 9
	
section .text

global _start
_start:
	mov eax, SYSTEM_WRITE	
	mov ebx, STDOUT	
	mov ecx, msg1
	mov edx, msg1len
	int 80h	
	
	mov eax, SYSTEM_READ	
	mov ebx, STDIN	
	mov ecx, num1
	mov edx, 9
	int 80h		
	
	mov eax, SYSTEM_WRITE	
	mov ebx, STDOUT
	mov ecx, msg2
	mov edx, msg2len
	int 80h
	
	mov eax, SYSTEM_READ	
	mov ebx, STDIN	
	mov ecx, num2
	mov edx, 9
	int 80h	
	
	mov edx, [num1]
	sub edx, '0'	
	mov al, [num2]
	sub al, '0'
	add edx,al
	add edx, '0'
	mov [num], edx
	
	mov eax, SYSTEM_WRITE
	mov ebx, STDOUT	
	mov ecx, msg3
	mov edx, msg3len
	int 80h 
	
	mov eax, SYSTEM_WRITE	
	mov ebx, STDOUT	
	mov ecx, num
	mov edx, 9
	int 80h
	
	mov eax, SYSTEM_WRITE	
	mov ebx, STDOUT	
	mov ecx, msg
	mov edx, msglen
	int 80h
	
	mov eax,SYSTEM_EXIT	
	mov ebx,0
	int 80h
	
