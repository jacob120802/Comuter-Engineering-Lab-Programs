segment .data
    msg1 db "Enter first number: "
    len1 equ $- msg1
    msg2 db "Enter second number: "
    len2 equ $- msg2
    msg3 db "The entered numbers are: ",10
    len3 equ $- msg3
    
    SYS_EXIT  equ 1
    SYS_READ  equ 3
    SYS_WRITE equ 4
    STDIN     equ 0
    STDOUT    equ 1
segment .bss
    num1 resb 5
    num2 resb 5 ;int-4bit+1sign
section .text
global _start
_start:
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg1
    mov edx, len1
    int 0x80

    mov eax, SYS_READ
    mov ebx, STDIN
    mov ecx, num1
    mov edx, 255
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg2
    mov edx, len2
    int 0x80

    mov eax, SYS_READ
    mov ebx, STDIN
    mov ecx, num2
    mov edx, 255
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg3
    mov edx, len3
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, num1
    mov edx, 5
    int 0x80
    
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, num2
    mov edx, 5
    int 0x80

    mov eax, SYS_EXIT
    mov ebx, STDIN
    int 0x80
	
