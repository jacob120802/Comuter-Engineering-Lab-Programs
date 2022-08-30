section .data
	msg1 db 'Enter elements of array:',10
	msg1len equ $-msg1
	msg2 db 'Even no. in array: '
	msg2len equ $-msg2
	msg3 db 'Enter no. of elements in array: '
	msg3len equ $-msg3
	msg4 db 'Odd no. in array: '
	msg4len equ $-msg4
	newline db '	',10
	newlinelen equ $-newline
	array dw 0,0,0,0,0,0,0,0,0	;array declaration & initialization
	arraylen equ 9    ; static array count

section .bss
	num resb 9
	element resb 9
	odd resb 9
	even resb 9
	rem resb 9
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

section .text
global _start
_start:
    write msg3, msg3len
    read num,9
    write msg1, msg1len

    mov eax,'0'
    mov [even],eax
	
    mov eax,'0'
    mov [odd],eax


    mov eax,[num]
    mov [i],eax

    mov esi,array
    mov eax,num
    
    inputelement:
        read element, 2 

        mov bx,[element]
        mov [esi],bx

        dec byte[num]
        inc esi

        cmp byte[num],'0'
        jne inputelement
    
    mov esi,array
    mov eax,i

    checkevenodd:
        mov eax,[esi]
        mov [element],eax
	
	 mov eax,4
         mov ebx,1
         mov ecx,''
         mov edx,0
         int 80h	

	mov al,[element]
	sub al,'0'
    	mov bl,'2'
	sub bl,'0'

	div bl

	add ah,'0'
	add al,'0'
	mov [rem],ah

        mov eax,[rem]
        mov ebx,'0'
        cmp eax,ebx
        je EVEN
        jne ODD

        EVEN:
            inc byte[even]
            jmp CMP
        
        ODD:
            inc byte[odd]
            jmp CMP

        CMP:
            dec byte[i]
            inc esi
        
            cmp byte[i],'0'
            jne checkevenodd

    write msg2, msg2len
    write even, 9
    write newline, newlinelen	    

    write msg4, msg4len
    write odd, 9
    write newline, newlinelen

    mov eax,1
    mov ebx,0
    int 80h

