section .data
	msg1 db 'Enter length of the rectangle:'
	msg1len equ $-msg1
	msg2 db 'Enter breadth of the rectangle:'
	msg2len equ $-msg2
	msg3 db 'Area of rectangle = '
	msg3len equ $-msg3	
	msg4 db 'Perimeter of rectangle = '
	msg4len equ $-msg4
	msg5 db 'Enter base of the triangle:'
	msg5len equ $-msg5
	msg6 db 'Enter height of the triangle:'
	msg6len equ $-msg6
	msg7 db 'Area of triangle = '
	msg7len equ $-msg7
    	msg9 db 'Enter the length of side 1:'
	msg9len equ $-msg9
	msg10 db 'Enter the length of side 2:'
	msg10len equ $-msg10
	msg11 db 'Enter the length of side 3:'
	msg11len equ $-msg11
	msg8 db 'Perimeter of triangle = '
	msg8len equ $-msg8
	newline db '',10
	newlinelength equ $-newline

section .bss
	len resb 2
	breadth resb 2
	base resb 2
	height resb 2
	area resb 2
	perimeter resb 2	
    	s1 resb 2	
    	s2 resb 2	
    	s3 resb 2	

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
	mov ecx,len
	mov edx,2
	int 80h
	
	mov eax,4
	mov ebx,1
	mov ecx,msg2
	mov edx,msg2len
	int 80h
	
	mov eax,3
	mov ebx,2
	mov ecx,breadth
	mov edx,2
	int 80h

	;RECTANGLE AREA
	mov eax,4
	mov ebx,1
	mov ecx,msg3
	mov edx,msg3len
	int 80h
	mov al,[len]
	sub al,'0'
	mov bl,[breadth]
	sub bl,'0'
	;ax = al x bl
	mul bl
	add ax,'0'
	mov [area],ax	
	mov eax,4
	mov ebx,1
	mov ecx,area
	mov edx,2
	int 80h

	mov eax,4
	mov ebx,1
	mov ecx,newline
	mov edx,newlinelength
	int 80h
	
	;RECTANGLE PERIMETER
	mov eax,4
	mov ebx,1
	mov ecx,msg4
	mov edx,msg4len
	int 80h
	mov al,[len]
	sub al,'0'
	mov bl,[breadth]
	sub bl,'0'
	add al,bl
	mov bl,'2'
    	sub bl,'0'
	mul bl
	add ax,'0'
	mov [perimeter],ax	
	mov eax,4
	mov ebx,1
	mov ecx,perimeter
	mov edx,2
	int 80h

	mov eax,4
	mov ebx,1
	mov ecx,newline
	mov edx,newlinelength
	int 80h
    	mov eax,4
	mov ebx,1
	mov ecx,newline
	mov edx,newlinelength
	int 80h

	mov eax,4
	mov ebx,1
	mov ecx,msg5
	mov edx,msg5len
	int 80h
	
	mov eax,3
	mov ebx,2
	mov ecx,base
	mov edx,2
	int 80h
	
	mov eax,4
	mov ebx,1
	mov ecx,msg6
	mov edx,msg6len
	int 80h
	
	mov eax,3
	mov ebx,2
	mov ecx,height
	mov edx,2
	int 80h

	;TRIANGLE AREA
	mov eax,4
	mov ebx,1
	mov ecx,msg7
	mov edx,msg7len
	int 80h
	mov al,[base]				
	sub al,'0'
	mov bl,[height]
	sub bl,'0'
	mul bl
    	add ax,'0'
    	mov [area],ax
    	mov al,[area]
    	mov bl,'2'
	sub al,'0'
	sub bl,'0'
	;ax=al/bl
	div bl
	add ax,'0'
	mov [area],ax		
	mov eax,4
	mov ebx,1
	mov ecx,area
	mov edx,2
	int 80h

	mov eax,4
	mov ebx,1
	mov ecx,newline
	mov edx,newlinelength
	int 80h
    	mov eax,4
	mov ebx,1
	mov ecx,newline
	mov edx,newlinelength
	int 80h

    	mov eax,4
	mov ebx,1
	mov ecx,msg9
	mov edx,msg9len
	int 80h
	
	mov eax,3
	mov ebx,2
	mov ecx,s1
	mov edx,2
	int 80h

    	mov eax,4
	mov ebx,1
	mov ecx,msg10
	mov edx,msg10len
	int 80h
	
	mov eax,3
	mov ebx,2
	mov ecx,s2
	mov edx,2
	int 80h

 	mov eax,4
	mov ebx,1
	mov ecx,msg11
	mov edx,msg11len
	int 80h
	
	mov eax,3
	mov ebx,2
	mov ecx,s3
	mov edx,2
	int 80h

	;TRIANGLE PERIMETER
	mov eax,4
	mov ebx,1
	mov ecx,msg8
	mov edx,msg8len
	int 80h
	mov al,[s1]
	sub al,'0'
	mov bl,[s2]
	sub bl,'0'
	add al,bl
    	mov bl,[s3]
    	sub bl,'0'
    	add al,bl
	add al,'0'
	mov [perimeter],al	
	mov eax,4
	mov ebx,1
	mov ecx,perimeter
	mov edx,2
	int 80h

	mov eax,4
	mov ebx,1
	mov ecx,newline
	mov edx,newlinelength
	int 80h

	mov eax,1
	mov ebx,0
	int 80h
