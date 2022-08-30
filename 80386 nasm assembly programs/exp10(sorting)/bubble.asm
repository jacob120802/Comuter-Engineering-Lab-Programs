section .data
	prompt db "Enter no. of elements: "
	plen equ $-prompt
	prompt2 db "Enter elements in array:",10
	p2len equ $-prompt2
	msg db "Array after each iteration process:",10
	msglen equ $-msg
	msg1 db "Final array after performing Bubble Sort:",10
	msg1len equ $-msg1
	newline db 10
	space db ' '
	
section .bss
	n resb 4
	arr resb 10
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
	mov eax,3
	mov ebx,2
	mov ecx,trash
	mov edx,1
	int 80h
%endmacro
	
section .text
global _start
_start:
	SYS_WRITE prompt,plen
	SYS_READ n,1
	
	call input
	SYS_WRITE msg,msglen
	call bubble_sort
	SYS_WRITE msg1,msg1len
	call display

	mov eax,1
	mov ebx,0
	int 80h

input:
	SYS_WRITE prompt2,p2len
	mov [i],dword '0'
loop1:
	mov esi,[i]
	cmp esi,[n]
	jge after1
	sub esi,'0'
	add esi,arr
	SYS_READ esi,1

	inc dword[i]
	jmp loop1	
after1:
	ret

display:
	mov [i],dword '0'
loop2:
	mov esi,[i]
	cmp esi,[n]
	jge after2
	sub esi,'0'
	add esi,arr
	SYS_WRITE esi,1
	SYS_WRITE space,1
	inc dword[i]
	jmp loop2	
after2:
	SYS_WRITE newline,1	
	ret

bubble_sort:
	mov al,0 		;al is counter for outer loop, initialise to 0
	mov bl,[n]
	sub bl,'0'
	sub bl,1		;bl is n-1
loop3:
	cmp al,bl		;repeat until al<n-1
	jge after3
	pushad
	call display
	popad
	mov ecx,0		;ecx is counter for inner loop, initialise to 0
	mov dl,bl
	sub dl,al		;dl is n-1-al
loop4:
	cmp cl,dl		;repeat until cl<n-1-al
	jge after4

	mov esi,arr
	add esi,ecx		;esi points to arr[ecx]

	mov ah,[esi]
	mov bh,[esi+1]
	cmp ah,bh
	jle after5		;if ah>bh

	mov [esi+1],ah		;swap esi and esi+1
	mov [esi],bh
after5:	
	inc cl
	jmp loop4
after4:
	inc al
	jmp loop3
after3:
	ret
