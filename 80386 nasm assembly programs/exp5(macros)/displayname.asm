;Write an assembly language program to print your name 7 times
section .data
msg1 db 'Enter your name:'
msg1len equ $-msg1
msg2 db 'Printing my name 7 times: ',10
msg2len equ $-msg2
newline db '',10
newlinelen equ $-newline

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

%macro displayname 2
    loop1:
        write %1,9
        mov ax,[%2]
        inc ax
        mov [%2],ax
        
        cmp ax,'7'        
        jle loop1
%endmacro

section .bss
name resb 9
count resb 9

section .text
global _start

_start:
    write msg1,msg1len
    read name,9
    
    mov ax, '1'
    mov [count],ax

    write msg2,msg2len
    displayname name,count
    
    mov eax,1
    mov ebx,0
    int 80h
