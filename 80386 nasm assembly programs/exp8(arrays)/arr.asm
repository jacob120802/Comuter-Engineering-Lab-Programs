section .data
	msg1 db 'Enter elements in array:',10
	msg1len equ $-msg1
	msg2 db 'Displaying elements in array:',10
	msg2len equ $-msg2
	msg3 db 'Enter no. of elements in array: '
	msg3len equ $-msg3
	newline db '	',10
	newlinelen equ $-newline
	tab db '    '
	tablen equ $-tab 
	array dw 0,0,0,0,0,0,0,0,0	;array declaration & initialization
	arraylen equ 9    ; static array count

section .bss
	num resb 9
	element resb 9
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
    read num, 9
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

    write msg2, msg2len 
    
    displayelement:
        mov eax,[esi]
        mov [element],eax

        write element,1
        write tab, tablen

        dec byte[i]
        inc esi
        
        cmp byte[i],'0'
        jne displayelement

    write newline, newlinelen
    
    mov eax,1
    mov ebx,0
    int 80h

