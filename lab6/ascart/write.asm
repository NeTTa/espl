section	.text
	global write

write:				;void write()
	push 	ebp		;function enty
	mov 	ebp, esp	;function enty
	mov	ebx,[ebp+8]	;file descriptor (stdout)
	mov	ecx,[ebp+12]	;char*
	mov 	edx,[ebp+16]	;length of char*

	mov	eax,4	;system call number (sys_write)
	int	0x80	;call kernel
	pop ebp
	ret