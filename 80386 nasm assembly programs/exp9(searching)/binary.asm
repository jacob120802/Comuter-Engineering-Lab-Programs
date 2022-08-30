section .data
	prompt db "Enter no. of elements: "
	plen equ $-prompt
	prompt2 db "Enter array elements (in increasing order):",10
	p2len equ $-prompt2
	prompt4 db "Enter element to search: "
	p4len equ $-prompt4
	prompt5 db "Element found at index: "
	p5len equ $-prompt5
	prompt6 db "Element not found in array.",10
	p6len equ $-prompt6	
	newline db 10
	
section .bss
	n resb 4
	num resb 4
	arr resb 10
	index resb 4
	lb resb 1
	ub resb 1
	mid resb 1
	trash resb 1

%macro SYS_WRITE 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
	
%macro SYS_READ 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
	mov eax,3
	mov ebx,2
	mov ecx,trash
	mov edx,1
	int 80h
%endmacro
	
section .text
global _start
_start:
	SYS_WRITE prompt,plen
	SYS_READ n,1
	sub [n],byte '0'

	SYS_WRITE prompt2,p2len
	mov eax,arr
	mov edx,[n]
	call input

	SYS_WRITE prompt4,p4len
	SYS_READ num,1
	mov eax,arr
	mov edx,[n]
	mov edi,[num]
	call binary_search
	
	SYS_WRITE newline, 1
	mov eax,1
	mov ebx,0
	int 80h

input:
	;; eax should contain address of array
	;; edx should contain size of array
	mov ecx,0
repeat_input:	
	cmp ecx,edx
	jge after_input
	mov esi,eax
	add esi,ecx
	pushad
	SYS_READ esi,1
	popad
	inc ecx
	jmp repeat_input
after_input:
	ret

binary_search:
;; edi should contain number to search
	and edi,000fh
	mov [lb],byte 0		;lb=0
	mov [ub],dl		;ub=n
repeat_search:
	pushad
	mov al,[lb]		;mid=(lb+ub)/2
	add al,[ub]
	cbw
	mov bl,2
	div bl
	mov [mid],al
	popad
	mov cl,[lb]
	mov dl,[ub]		;we don't need value of n anymore
	cmp cl,dl
	jg after_search		;exit loop if lb>ub
	mov edx,[mid]
	and edx,000fh
	mov esi,dword eax[edx]
	and esi,000fh		;esi=arr[mid]
	cmp edi,esi
	je matched		;num == arr[mid]
	jl lower_part		;num < arr[mid]
upper_part:
	mov bl,[mid]
	add bl,1
	mov [lb],bl		;lb=mid+1
	jmp repeat_search
lower_part:
	mov bl,[mid]
	sub bl,1
	mov [ub],bl		;ub=mid-1
	jmp repeat_search	
matched:
	;display result
	add edx,'0'	
	mov [index],edx			
	pushad
	SYS_WRITE prompt5,p5len		
	SYS_WRITE index,1		
	popad				
	ret				
after_search:
	;display not found 
	SYS_WRITE prompt6,p6len
	ret
	
