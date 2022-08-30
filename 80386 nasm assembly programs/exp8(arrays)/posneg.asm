section .data
	msg1 db 'Count of positive and negative numbers in an array ',10
	msg1len equ $-msg1
	msg db 'Elements in array are: 10,-21,45,12,-25,43,78,96,-89',10
	msglen equ $-msg
	msg2 db 'Positive count:'
	msg2len equ $-msg2
	msg3 db 'Negative count:'
	msg3len equ $-msg3
	newline db '	',10
	newlinelen equ $-newline
	array dw 10,-21,45,12,-25,43,78,96,-89	;array declaration & initialization
	arrcnt equ 9    ; static array count
	pcnt dw 0       ; positive number count
	ncnt dw 0      ; negative number count

section .bss
	dis_buffer resb 2
	
%macro write 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro

section .text
global _start
_start:
    write msg1, msg1len
    write msg, msglen

    ; Initializating array start address
    mov esi,array
    mov ecx,arrcnt
    UP:
        BT word[esi],15
        JC NCXT
        inc byte[pcnt]
        JMP PSKIP

        NCXT: 
            inc byte[ncnt]
        
        PSKIP:  
            inc esi
            inc esi
            loop UP

    write msg2, msg2len		; Positive count msg display

    mov bl,[pcnt]
    CALL HEX_ASCII

    write newline, newlinelen	
    
    write msg3, msg3len		; Negative count msg display

    mov bl,[ncnt]
    CALL HEX_ASCII

    write newline, newlinelen

    mov eax,1
    mov ebx,0
    int 80h

; HEX TO ASCII procedure
HEX_ASCII: 
    mov ecx,2
    mov edi,dis_buffer
    DUP: 
        rol bl,04
        mov al,bl
        and al,0fh
        cmp al,09h
        jbe NEXT
        add al,07h

        NEXT: 
            add al,30h
            mov [edi],al
            inc edi
            loop DUP

    ; display count
    write dis_buffer, 2
RET
