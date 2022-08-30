; Write an assembly language to implement linear search
section .data
msg1 db 'Enter the number of elements in the array: '
msg1len equ $-msg1
msg2 db 'Enter the elements of the array:',10
msg2len equ $-msg2
msg3 db 'Enter the element to be searched:'
msg3len equ $-msg3
msg4 db 'Element found at index '
msg4len equ $-msg4
msg5 db 'Element not found',10
msg5len equ $-msg5
newline db '	',10
newlinelen equ $-newline

;array declaration and initialization
array dw 0,0,0,0,0,0,0,0,0
arraylen equ 9    ; static array count

section .bss
num resb 9
element resb 9
i resb 9
n resb 9
index resb 9

%macro write_message 2
    mov eax,4
    mov ebx,1
    mov ecx,%1
    mov edx,%2
    int 80h
%endmacro

%macro read_message 2
    mov eax,3
    mov ebx,2
    mov ecx,%1
    mov edx,%2
    int 80h
%endmacro

section .text
global _start

_start:
    write_message msg1,msg1len
    read_message num,9
    write_message msg2,msg2len

    mov eax,[num]
    mov [i],eax

    mov esi,array
    mov eax,num
    
    inputelement:
        mov eax,3
        mov ebx,2
        mov ecx,element
        mov edx,2
        int 80h 

        mov ebx,[element]
        mov [esi],ebx

        dec byte[i]
        inc esi

        cmp byte[i],'0'
        jne inputelement

    write_message msg3,msg3len
    read_message n,9

    mov eax,[num]
    mov [i],eax

    mov esi,array
    mov eax,i

    linearSearch:
        mov eax,[esi]
        mov [element],eax

        mov al,[n]
        sub al,'0'
        mov bl,[element]
        sub bl,'0'
        cmp al,bl
        je exit

        dec byte[i]
        inc esi
        
        cmp byte[i],'0'
        jne linearSearch
    
    write_message msg5,msg5len

    mov eax,1
    mov ebx,0
    int 80h
    
    exit:
        write_message msg4,msg4len

        mov eax,[num]
        sub eax,'0'
        mov ebx,[i]
        sub ebx,'0'
        sub eax,ebx
        add eax,'0'
        mov [index],eax

        write_message index,9
        write_message newline,newlinelen

        mov eax,1
        mov ebx,0
        int 80h