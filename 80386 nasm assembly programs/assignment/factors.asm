section .data
	prompt db "Factors are",10
	plen equ $-prompt
	newline db 10
	
section .bss
	n resb 4
	arr resd 10
	i resb 4
	trash resb 1

%macro SYS_WRITE 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
	
%macro SYS_READ 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
	
section .text
	global _start

_start:
	SYS_WRITE prompt,plen
	
	call factors
	call display

	mov eax,1
	mov ebx,0
	int 80h

display:
	mov [i],dword 0
loop2:
	mov esi,[i]
	cmp esi,[n]
	jge after2

	mov eax,esi
	mov ebx,4
	mul ebx
	mov esi,eax
	add esi,arr
	SYS_WRITE esi,1
	SYS_WRITE newline,1

	inc dword[i]
	jmp loop2	
after2:
	ret


factors:
	mov [n],dword 0		;initialise n=0

	mov ecx,1		;ecx=1
loop3:
	cmp ecx,100
	jg after3		;loop until ecx<=100

	mov eax,100
	cdq
	div ecx			;perform division of 100 by ecx to get remainder

	cmp edx,0		;check if remainder is 0
	jne after4

	mov edx,[n]
	mov arr[edx*4],ecx	;arr[n]=ecx
	inc dword[n]		;n++
after4:	
	inc ecx			;ecx++
	jmp loop3
after3:
	ret
