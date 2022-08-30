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

section .text

global _start

_start:
	mov eax,4
	mov ebx,1
	mov ecx,msg1
	mov edx,msg1len
	int 80h
	
	mov eax,3
    	mov ebx,2
	mov ecx,n
	mov edx,9
	int 80h

	mov eax,4
    	mov ebx,1
    	mov ecx,msg2
    	mov edx,msg2len
    	int 80h	
    	
    	mov al,'0'
	mov [a],al
	mov al,'1'
	mov [b],al
	
	cmp byte[n],'0'
	jle exit
	
	mov eax,4
	mov ebx,1
	mov ecx,a
	mov edx,9
	int 80h
	
    	mov eax,4
    	mov ebx,1
    	mov ecx,newtab
    	mov edx,newtablen
    	int 80h
    	
	cmp byte[n],'2'
	jl exit

	mov eax,4
	mov ebx,1
	mov ecx,b
	mov edx,9
	int 80h
	
    	mov eax,4
    	mov ebx,1
    	mov ecx,newtab
    	mov edx,newtablen
    	int 80h
    	
	cmp byte[n],'3'
	jl exit
	mov al,'2'
	mov [i],al
	call fibonacci 
	
    fibonacci:
		mov eax,[a]
		sub eax,'0'
		mov ebx,[b]
		sub ebx,'0'
		add eax,ebx
		add eax,'0'
		add ebx,'0'
		mov [a],ebx
		mov [b],eax
		mov eax,4
		mov ebx,1
		mov ecx,b
		mov edx,9
		int 80h		          
        	mov eax,4
    		mov ebx,1
    		mov ecx,newtab
    		mov edx,newtablen
    		int 80h
		inc byte[i]
		mov al,[i]
		cmp byte[n],al
		je exit
		jmp fibonacci
		ret

    exit:
    	mov eax,4
    	mov ebx,1
    	mov ecx,newline
    	mov edx,newlinelen
    	int 80h
        mov eax,1
        mov ebx,0
        int 80h
