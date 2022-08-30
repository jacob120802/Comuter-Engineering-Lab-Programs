; Write an assembly language program to implement binary search
section .data
msg1 db 'Enter the elements of the array:',10
msg1len equ $-msg1
msg3 db 'Enter the number of elements in the array:'
msg3len equ $-msg3
msg4 db 'Element found at index '
msg4len equ $-msg4
msg5 db 'Element not found '
msg5len equ $-msg5
msg6 db 'Enter the element to be searched:'
msg6len equ $-msg6
newline db '    ',10
newlinelen equ $-newline

;array declaration and initialization
array dw 0,0,0,0,0,0,0,0,0
arraylen equ 9    ; static array count

section .bss
num resb 9
element resb 9
ele resb 9
i resb 9
l resb 9
h resb 9
mid resb 9
count resb 9

%macro calc_mid 3
    mov eax,4
    mov ebx,1
    mov ecx,''
    mov edx,0
    int 80h 

    mov al,[%1]    
    sub al,'0'
    mov bl,[%2]
    sub bl,'0'
    add al,bl
    mov bl,'2'
    sub bl,'0'
    div bl
    add ax,'0'
    mov [%3],ax
%endmacro

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
    write_message msg3,msg3len
    read_message num,9
    write_message msg1,msg1len

    mov eax,[num]
    mov [i],eax

    mov esi,array
    mov eax,num
    
    inputelement:
        read_message element,2

        mov ebx,[element]
        mov [esi],ebx

        dec byte[num]
        inc esi

        cmp byte[num],'0'
        jne inputelement

    write_message msg6,msg6len
    read_message ele,9

    mov ebx,'0'
    mov [l],ebx
    mov eax,[i]
    mov [h],eax
    dec byte[h]

    calc_mid l,h,mid

    mov eax,[count]
    mov [mid],eax
    
    mov esi,array
    mov eax,i

    mov esi,array
    mov eax,i
    jmp search

    inc_1:
        inc byte[count]
        dec byte[mid]
        call float_int

    float_int:
        cmp byte[mid],'1'
        jge inc_1
        ret

    incr:
        inc esi
        inc bl
        jmp array_index

    array_index:
        cmp al,bl
        jge incr
        ret

    search:
        mov al,[l]
        mov bl,[h]
        cmp al,bl
        jg not_found 

        calc_mid l,h,mid
        mov al,'0'
        mov [count],al
        call float_int

        mov esi,array
        mov eax,[i]

        mov al,[count]
        mov bl,'1'
        call array_index

        mov eax,[esi]
        mov [element],eax

        mov al,[ele]
        mov bl,[element]

        cmp al,bl
        jl left
        jg right
        je found

        left:
            mov al,[count]
            sub al,'0'
            mov bl,'1'
            sub bl,'0'
            sub al,bl
            add al,'0'
            mov [h],al
            jmp search

        right:
            mov al,[count]
            sub al,'0'
            mov bl,'1'
            sub bl,'0'
            add al,bl
            add al,'0'
            mov [l],al
            jmp search

        found:
            ;inc byte[count]

            write_message msg4,msg4len
            write_message count,9
            jmp exit

        not_found:
            write_message msg5,msg5len

    exit:
        write_message newline,newlinelen

        mov eax,1
        mov ebx,0
        int 80h