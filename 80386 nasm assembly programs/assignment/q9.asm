section .data
	prompt db "Enter a number",10
	plen equ $-prompt
	result db "Sum is "
	rlen equ $-result

section .bss
	arr resd 5
	num resd 1

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
	mov edi,0
	mov eax,edi
	mov ebx,4
	mul ebx
	add eax,arr
	mov esi,eax
	SYS_READ esi,2

	inc edi
	jmp loop0
	
	mov eax,1
	mov ebx,0
	int 80h
	
loop0:
	SYS_WRITE prompt,plen
	cmp edi,5
	jge after0
	
after0:
	mov eax,0
	mov ecx,0
	
loop:
	cmp ecx,5
	jge after
	add eax,arr[4*ecx]
	sub eax,'0'
	inc ecx
	jmp loop
	
after:
	mov [num],eax
	add [num],dword '0'
	SYS_WRITE num,1
