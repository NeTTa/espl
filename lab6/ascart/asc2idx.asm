section	.text
	global asc2idx

asc2idx:			;void asc2idx()
	push 	ebp		;function enty
	mov 	ebp, esp	;function enty
	mov	eax,[ebp+8]	;file descriptor (stdout)
	sub	eax, 32
	pop ebp
	ret