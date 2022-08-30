%macro write_string 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
	
section .data
	msg1 db 'MPMC ' 
	msg1len equ $-msg1
	msg2 db 'EXPERIMENT-5',10 
	msg2len equ $-msg2

section .text

global _start
_start:
	write_string msg1, msg1len
	write_string msg2, msg2len

	mov eax,1
	mov ebx,0
	int 80h
