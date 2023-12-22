;CS2150 PostLab 8
;linearSearch.s
;
	
	global linearSearch


	section .text



;Parameter 1 is a pointer to the int array rdi
;Parameter 2 is the size of the array rsi
;Parameter 3 is the integer representing target element rdx

linearSearch:
	;Implementation of linearSearch


	xor rax, rax ; zero out the return register 
	xor r10, r10 ; zero out the counter i 
	
	
start: 
	cmp r10, rsi; if i =n 
	je not_found ; integer not in array 
	
	cmp edx, [rdi+4*r10] ; compare integer to the target element
	je found ; jmp to found
	inc r10  ; increment i 
	jmp start ; jmp back to start

found:
	mov rax, r10 
	jmp done


not_found:
	mov rax, -1
	jmp done

done: 
	ret