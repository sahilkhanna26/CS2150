;CS2150 PostLab 9
;Binary Search
;
	

	global binarySearch


	section .text

;Parameter 1 is a pointer to the int array rdi
;Parameter 2 is int at beginning of the array rsi
;Parameter 3 is int at end of the array rdx
;Parameter 4 is the integer representing target element rcx

binarySearch:
	;implementation of binarysearch


	xor rax, rax ; zero out the return register 
	xor r10, r10 ; zero out the register pointing to middle


start:

	cmp edx, esi
	jl not_found

	mov r10, rdx; find index of midpoint (midpt = low+high/2)
	add r10, rsi 
	shr r10, 1 ; divide by two with a bitshift

	cmp ecx, [rdi + 4*r10]
	je found

	cmp ecx, [rdi + 4*r10]
	jg greater

	cmp ecx, [rdi + 4*r10]
	jl lesser

lesser:
	sub r10, 1;
	mov rdx, r10
	jmp start

greater:
	add r10, 1;
	mov rsi, r10
	jmp start

found:
	mov rax, r10;
	ret 

not_found:
	mov rax, -1;
	ret
