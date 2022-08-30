section .data
	hello db 'HELLO JACOB ' ,12
	intro db 'HOW ARE YOU ?' ,13

section .text

global _start
_start:
	mov eax,4
	mov ebx,1
	mov ecx,hello
	mov edx,12
	int 80h
	
	mov eax,4
	mov ebx,1
	mov ecx,intro
	mov edx,13
	int 80h

	mov eax,1
	mov ebx,0
	int 80h
