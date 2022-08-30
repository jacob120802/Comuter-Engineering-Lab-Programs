section .data
stars times 9 db '*'
sLen equ $-stars

section .text
global _start

_start:
	mov eax,4
	mov ebx,1
	mov ecx, stars
	mov edx, sLen
int 80h
	mov eax,1
	mov ebx,0
int 80h
