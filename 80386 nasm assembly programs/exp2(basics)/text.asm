section .data
	hello db 'HELLO JACOB' ,10
	hellolen equ $-hello

section .text

global _start
_start:
	mov eax,4
	mov ebx,1
	mov ecx,hello
	mov edx,hellolen
	int 80h

	mov eax,1
	mov ebx,0
	int 80h
	
