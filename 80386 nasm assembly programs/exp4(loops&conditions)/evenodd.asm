section .data
	msg1 db'Enter a number: '
	len1 equ $-msg1
	msg2 db'Entered number is Even',10
	len2 equ $-msg2
	msg3 db'Entered number is Odd',10
	len3 equ $-msg3

section .bss
 	num resb 2

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
	    mov bl, '2'
	    ; Convert from ascii to decimal
	    sub al, '0'
	    sub bl, '0'
	    ; Division. AH= AL / BL
	    div bl
	    ; Conversion from decimal to ascii
	    add al, '0'
	    add ah, '0'
	    ; We move the result
	    mov bl, '0'
	    cmp ah, bl
	    jle iseven
	    jg isodd

	isodd:
		mov eax,4
		mov ebx,1
		mov ecx,msg3
		mov edx,len3
		int 80h
		jmp exit

	iseven:
		mov eax,4
		mov ebx,1
		mov ecx,msg2
		mov edx,len2
		int 80h
		jmp exit

	exit:
		mov eax,1
		mov ebx,0
		int 80h
