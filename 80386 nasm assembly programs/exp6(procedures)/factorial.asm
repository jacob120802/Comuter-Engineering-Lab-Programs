section .data
	msg1 db 'Enter the number:'
	msg1len equ $-msg1
	msg2 db 'The factorial of entered number is: ',10
	msg2len equ $-msg2
	newtab db '	'
	newtablen equ $-newtab
	newline db '',10
	newlinelen equ $-newline

section .bss
	n resb 9
	result resb 9

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
    	
    	mov al,'1'
	mov [result],al
	
	cmp byte[n],'0'
	jl exit
	je equal
	jg greater
	
equal:
	mov eax,4
	mov ebx,1
	mov ecx,result
	mov edx,9
	int 80h
	jmp exit
    		
greater:    	
	cmp byte[n],'1'
	jne fact
	je l2

l2:
	mov eax,4
	mov ebx,1
	mov ecx,result
	mov edx,9
	int 80h
	jmp exit
			
fact:
	call factorial
	jmp greater  
	 
factorial: 
	mov al,[result]
	sub al,'0'
	mov bl,[n]
	sub bl,'0'
	mul bl
	add al,'0'
	add bl,'0'
	mov [result],al
	mov [n],bl
	mov ebx, [n]
	dec ebx
	mov [n], ebx
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
