
section .data
	msg1 db'Enter a number: '
	len1 equ $-msg1
	msg2 db'Entered number is Lesser than 5',10
	len2 equ $-msg2
	msg3 db'Entered number is Greater than 5',10
	len3 equ $-msg3
	msg4 db'Entered number is 5 itself',10
	len4 equ $-msg4
section .bss
 	num resb 5
 

section .text

global _start
_start:

	mov eax,4
	mov ebx,1
	mov ecx,msg1
	mov edx,len1
	int 80h

	mov eax,3
	mov ebx,2
	mov ecx,num
	mov edx,2
	int 80h


	    mov al, [num]
	    mov bl, '5'
	    cmp al, bl
	    jl islesser
	    jg isgreater
	    je isequal

	islesser:
		mov eax,4
		mov ebx,1
		mov ecx,msg2
		mov edx,len2
		int 80h
		jmp exit

	isequal:
		mov eax,4
		mov ebx,1
		mov ecx,msg4
		mov edx,len4
		int 80h
		jmp exit
	

	isgreater:
		mov eax,4
		mov ebx,1
		mov ecx,msg3
		mov edx,len3
		int 80h
		jmp exit
	exit:
		mov eax,1
		mov ebx,0
		int 80h
