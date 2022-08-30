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
	msg4 db 'Enter your third number:'	
	msg4len equ $-msg4	
	msg3 db 'After Addition of the 2 input numbers result is:',10	
	msg3len equ $-msg3
	msg  db '',10
	msglen equ $-msg
	
section .bss
	num1 resb 9
	num2 resb 9
	num3 resb 9
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
	
	mov eax, SYSTEM_WRITE	
	mov ebx, STDOUT
	mov ecx, msg4
	mov edx, msg4len
	int 80h
	
	mov eax, SYSTEM_READ	
	mov ebx, STDIN	
	mov ecx, num3
	mov edx, 9
	int 80h	
	
	mov al, [num1]
	sub al, '0'	
	mov bl, [num2]
	sub bl, '0'
	add al,bl
	mov bl, [num3]
	sub bl, '0'
	add al,bl
	add al, '0'
	mov [num], al
	
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
	
