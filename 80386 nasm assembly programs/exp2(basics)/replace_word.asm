section .data
msg1 db 'Original text: '
m1Len equ $-msg1
msg2 db 'Modified text: '
m2Len equ $-msg2
hello db 'hello world',10
helloLen equ $-hello

section .text
global _start

_start:
	mov eax,4
	mov ebx,1
	mov ecx,msg1
	mov edx,m1Len
int 80h
	mov eax,4
	mov ebx,1
	mov ecx,hello
	mov edx,helloLen
int 80h
	mov eax,4
	mov ebx,1
	mov ecx, msg2
	mov edx, m2Len
int 80h
	mov eax,4
	mov ebx,1
	mov [hello],dword 'bye '
	mov ecx,hello
	mov edx,helloLen
int 80h
	mov eax,1
	mov ebx,0
int 80h
