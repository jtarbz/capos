global _init:function
global _fini:function

section .init
_init:
	push ebp
	mov ebp, esp

section .fini
_fini:
	push ebp
	mov ebp, esp
