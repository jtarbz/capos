global inb:function
global outb:function

inb:
	xor eax, eax	; this may not be necessary ...
	mov dx, [esp + 4]
	in al, dx
	ret

outb:
	mov al, [esp + 8]
	mov dx, [esp + 4]
	out dx, al
	ret
