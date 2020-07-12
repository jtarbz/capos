ALIGNMENT	equ 1 << 0			; align to page boundaries
MEMINFO 	equ 1 << 1			; provide memory map
VIDEO		equ 1 << 2			; we want video stuff
FLAGS 		equ ALIGNMENT | MEMINFO	| VIDEO	; build the flag field
MAGIC 		equ 0x1badb002			; fun magic number
CHECKSUM 	equ -(MAGIC + FLAGS)		; epic checksum
VIDMODE		equ 1				; text mode
WIDTH		equ 80				; columns
HEIGHT		equ 24				; rows
DEPTH		equ 0				; bits per pixel (does not apply)

global _start:function (_start.end - _start)
global wrap_lgdt:function (wrap_lgdt.end - wrap_lgdt)
global wrap_lidt:function (wrap_lidt.end - wrap_lidt)
extern _init
extern caposk

; declare multiboot standard header
section .multiboot
	align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM
	dd 0		; lots of options for flags we didn't set
	dd 0
	dd 0
	dd 0
	dd 0
	dd VIDMODE
	dd WIDTH
	dd HEIGHT
	dd DEPTH

; reserve a stack for initial thread
section .bss
	align 16
	stack_bottom:
	resb 16384	; 16 kib
	stack_top:

; kernel entry point
; NOTE: multiboot drops us in protected mode and sets up a basic gdt for us,
; which is only guaranteed to be 4 gib with overlapping data / code. it would
; be wise to establish our own gdt in the future
section .text
_start:
	mov esp, stack_top
	call _init
	call caposk

	cli
.hang:	hlt
	jmp .hang
	.end:

; finding these guys a home here, as i consider them part of the boot sequence
wrap_lgdt:
	mov eax, [esp + 4]
	lgdt [eax]
	
	mov ax, 0x10	; this is our data segment
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:flush	; this tells the processor where the code segment is
	.end:

flush:
	ret

wrap_lidt:
	mov eax, [esp + 4]
	lidt [eax]
	ret
	.end:
