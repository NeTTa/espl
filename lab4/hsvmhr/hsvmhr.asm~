section .text
global hsvmhr
hsvmhr:
	push	ebp			;enter function
	mov	ebp, esp		;enter function
.L5:
	mov	eax, [ebp+8]
	mov	eax, [eax]
	mov	edx, [ebp+12]
	mov	edx, [edx]
	movzx eax, al
	movzx edx, dl
	sub	eax, edx
	je	.L2
	jmp	.L3
.L2:
	test dl, dl			;compare dl with 0
	jne	.L4			;execute if dl != 0
	xor	eax, eax		;zeroing eax
	jmp	.L3		
.L4:
	add	DWORD [ebp+8], 1
	add	DWORD [ebp+12], 1
	jmp	.L5
.L3:
	pop	ebp			;exit function
	ret				;exit function