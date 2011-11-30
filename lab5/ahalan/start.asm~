section .text
	global _start

extern main
_start:
	mov	eax,esp
	ADD	eax,4
	push	eax
	push	DWORD [esp+4]

	call	main
        mov     ebx,eax
	ADD	esp,8

	mov	eax,1
	int 0x80
