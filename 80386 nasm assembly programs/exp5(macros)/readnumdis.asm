%macro write_sys_call 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro

%macro read 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
	
section .data
	msg1 db 'Enter a number:' ,10
	msg1len equ $-msg1
	msg2 db 'Number entered is '
	msg2len equ $-msg2	
section .bss
	num resb 9

section .text

global _start
_start:
	write_sys_call msg1, msg1len
	read num,9
	write_sys_call msg2, msg2len
	write_sys_call num, 9
	mov eax,1
	mov ebx,0
	int 80h
