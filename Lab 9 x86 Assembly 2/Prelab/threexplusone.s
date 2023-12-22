;CS 2150 Prelab 9
;Collatz Conjecture


	global threexplusone

	section .text


;parameter 1 is the integer in rdi

threexplusone:
	
	xor rax, rax; zero out the return register
	xor r8, r8; zero out counter


start:
	cmp rdi, 1
	je done
	mov rdx, rdi;
	add r8, 1
	and rdx, 001;checking if even or odd
	cmp rdx, 1; check if odd
	je odd
	jmp even

odd:
	lea rdi, [rdi*2 +rdi] ;rdi*3 (OPTIMIZATION: faster multiplication)
	add rdi, 1; edi = 3x+1 
	jmp start

even:
	sar rdi, 1 ; divide by 2 (OPTIMIZATION: Bit Shift- shift right)
	jmp start

done:
	mov rax, r8
	ret


