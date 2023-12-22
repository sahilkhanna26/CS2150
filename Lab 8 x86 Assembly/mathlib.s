; mathlib.s
;
; Purpose : This file contains the implementation of the functions
;           product and power, multiply two numbers and compute the power of 2 numbers respectively.
;
; Parameter 1 (in rdi) is the first number
; Parameter 2 (in rsi) is the second number 
; Return value is a long that is the result of the product or power of the integers in the sequence
;

	global product
	global power




	section .text

product:
	; Standard prologue
	; Subroutine body:

	xor rax, rax ;zeroing the return register
	xor r10, r10 ;zeroing the counter i 

start1:
	cmp r10,rsi ; does i == n 
	je done1
	add rax, rdi ; add rdi to rax 
	inc r10 ;increment counter i 
	jmp start1 ;end loop iteration

done1:
	ret ; end function


power:

	xor rax, rax ;zeroing the return register
	xor rcx, rcx ; zeroing r10 
	add rcx, rsi;
	mov rsi, rdi



	

checker:
	cmp rcx,1 ; does counter == 0 
	je done2 
	jmp multiplier

multiplier:
	call product
	mov rdi,rax
	dec rcx;
	jmp checker
	
done2:
	mov rax,rdi
	
	ret;


