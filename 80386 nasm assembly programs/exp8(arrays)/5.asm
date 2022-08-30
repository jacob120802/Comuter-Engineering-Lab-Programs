section .data
	msg1 db 'Enter elements of array:',10
	msg1len equ $-msg1
	msg2 db 'Enter no. of elements in array: '
	msg2len equ $-msg2
	msg3 db 'No. of elements above 5: '
	msg3len equ $-msg3
	msg4 db 'No. of elements below 5: '
	msg4len equ $-msg4
	newline db '	',10
	newlinelen equ $-newline
	array dw 0,0,0,0,0,0,0,0,0	;array declaration & initialization
	arraylen equ 9                  ; static array count

section .bss
	num resb 9
	element resb 9
	i resb 9
	above resb 9
	below resb 9
	
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
    write msg2, msg2len
    read num,9
    write msg1, msg1len

    mov eax,[num]
    mov [i],eax

    mov esi,array
    mov eax,num
    
    inputelement:
        read element, 2

        mov ebx,[element]
        mov [esi],ebx

        dec byte[num]
        inc esi

        cmp byte[num],'0'
        jne inputelement
    
    mov esi,array
    mov eax,i

    mov byte[above],'0'
    mov byte[below],'0'

    ABOVE_BELOW:
        mov eax,[esi]
        mov [element],eax

        mov al,[element]
        mov bl,'5'
        cmp al,bl
        jl LESS
        jg GREATER

        LESS:
            inc byte[below]
            jmp CMP

        GREATER:
            inc byte[above]
            jmp CMP
        
        CMP:
            dec byte[i]
            inc esi
        
            cmp byte[i],'0'
            jne ABOVE_BELOW

    write msg3, msg3len
    write above, 9
    write newline, newlinelen

    write msg4, msg4len
    write below, 9
    write newline, newlinelen

    mov eax,1
    mov ebx,0
    int 80h


