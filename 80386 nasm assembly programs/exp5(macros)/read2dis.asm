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
	msg1 db 'Enter 1st string: ' 
	msg1len equ $-msg1
	msg3 db 'Enter 2nd string: ' 
	msg3len equ $-msg3
	msg2 db 'Displaying entered strings: ',10
	msg2len equ $-msg2	
section .bss
	num resb 9
	num2 resb 9

section .text

global _start
_start:
	write_sys_call msg1, msg1len
	read num,9
	write_sys_call msg3, msg3len
	read num2,9
	write_sys_call msg2, msg2len
	write_sys_call num, 9
	write_sys_call num2, 9
	mov eax,1
	mov ebx,0
	int 80h
