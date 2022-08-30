;macro with 2 parameter
;implement wrie system call
%macro write_string 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
	
section .data
	msg1 db '7' ,10
	msg1len equ $-msg1

section .text

global _start
_start:
	write_string msg1, msg1len

	mov eax,1
	mov ebx,0
	int 80h
