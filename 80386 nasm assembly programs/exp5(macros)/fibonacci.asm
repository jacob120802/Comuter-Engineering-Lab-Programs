section .data
	msg1 db 'Enter the value of n:'
	msg1len equ $-msg1
	msg2 db 'The fibonacci series upto n: ',10
	msg2len equ $-msg2
	newtab db '	'
	newtablen equ $-newtab
	newline db '',10
	newlinelen equ $-newline

section .bss
	n resb 9
	a resb 9
	b resb 9
	i resb 9

%macro write 2
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

%macro fib 4
fibonacci:
		mov eax,[%2]
		sub eax,'0'
		mov ebx,[%3]
		sub ebx,'0'
		add eax,ebx
		add eax,'0'
		add ebx,'0'
		mov [%2],ebx
		mov [%3],eax
		write %3,9		          
        	write newtab,newtablen
		inc byte[%4]
		mov al,[%4]
		cmp byte[%1],al
		je exit
		jmp fibonacci
%endmacro

section .text

global _start

_start:
	write msg1,msg1len
	read n,9

	write msg2,msg2len

    	mov al,'0'
	mov [a],al
	mov al,'1'
	mov [b],al
	
	cmp byte[n],'0'
	jle exit
	
	write a,9
    	write newtab,newtablen
	cmp byte[n],'2'
	jl exit

	write b,9
    	write newtab,newtablen
	cmp byte[n],'3'
	jl exit
	mov al,'2'
	mov [i],al
	fib n,a,b,i

    exit:
    	write newline,newlinelen
        mov eax,1
        mov ebx,0
        int 80h
