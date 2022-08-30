section .data
    msg1 db 'Enter the initial point: '
    msg1len equ $-msg1
    msg2 db 'Displaying 5 consicutive no. starting from inital point:  ',10
    msg2len equ $-msg2
    
section .bss
	num resb 2
 
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
	mov ecx,num
	mov edx,2
	int 80h
	
	mov eax,4
	mov ebx,1
	mov ecx,msg2
	mov edx,msg2len
	int 80h
	
	mov eax,4
	mov ebx,1
	mov ecx,num
	mov edx,2
	int 80h
	
	mov al,[num]
	inc al
	mov [num],al
	
	mov eax,4
	mov ebx,1
	mov ecx,num
	mov edx,2
	int 80h
	
	mov al,[num]
	inc al
	mov [num],al
	
	mov eax,4
	mov ebx,1
	mov ecx,num
	mov edx,2
	int 80h
	
	mov al,[num]
	inc al
	mov [num],al
	
	mov eax,4
	mov ebx,1
	mov ecx,num
	mov edx,2
	int 80h
	
	mov al,[num]
	inc al
	mov [num],al
	
	mov eax,4
	mov ebx,1
	mov ecx,num
	mov edx,2
	int 80h
	
	mov eax,1
	mov ebx,0
	int 80h
	mov ebx,0
	int 80h
	
