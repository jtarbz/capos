#include "include/isr.h"
#include "include/util.h"
#include "include/keyboard.h"

__attribute__((interrupt))
void int0(struct int_frame *frame)
{
	printf("divide by zero error (fault)\n");
}

__attribute__((interrupt))
void int1(struct int_frame *frame)
{
	printf("debug fault / trap (ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int2(struct int_frame *frame)
{
	printf("non-maskable interrupt\n");
}

__attribute__((interrupt))
void int3(struct int_frame *frame)
{
	printf("breakpoint (trap, ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int4(struct int_frame *frame)
{
	printf("overflow exception (ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int5(struct int_frame *frame)
{
	printf("bound range exceeded (ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int6(struct int_frame *frame)
{
	printf("invalid opcode (ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int7(struct int_frame *frame)
{
	printf("device not available (fault, ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int8(struct int_frame *frame)
{
	printf("double fault (abort, err: %x)\n", frame->err);
}

__attribute__((interrupt))
void int9(struct int_frame *frame)
{
	printf("coprocessor segment overrun. this shouldn't show up\n");
}

__attribute__((interrupt))
void inta(struct int_frame *frame)
{
	printf("invalid tss (fault, ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void intb(struct int_frame *frame)
{
	printf("segment not present (fault, ip: %x, err: %x)\n", frame->eip, frame->err);
}

__attribute__((interrupt))
void intc(struct int_frame *frame)
{
	printf("stack segment fault (ip: %x, err: %x)\n", frame->eip, frame->err);
}

__attribute__((interrupt))
void intd(struct int_frame *frame)
{
	printf("general protection fault (ip: %x, err: %x)\n", frame->eip, frame->err);
}

__attribute__((interrupt))
void inte(struct int_frame *frame)
{
	printf("page fault (ip: %x, err: %x)\n", frame->eip, frame->err);
}

__attribute__((interrupt))
void int10(struct int_frame *frame)
{
	printf("x87 floating point exception (ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int11(struct int_frame *frame)
{
	printf("alignment check exception (ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int12(struct int_frame *frame)
{
	printf("machine check exception (ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int13(struct int_frame *frame)
{
	printf("simd floating point exception (ip: %x)\n", frame->eip);
}

__attribute__((interrupt))
void int14(struct int_frame *frame)
{
	printf("virtualization exception (???)\n");
}

__attribute__((interrupt))
void int1e(struct int_frame *frame)
{
	printf("security exception (err: %x)\n", frame->err);
}

__attribute__((interrupt))
void irq0(struct int_frame *frame)
{
	outb(0x20, 0x20);
}

/* keyboard handler */
__attribute__((interrupt))
void irq1(struct int_frame *frame)
{
	keyboard_handler();

	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irq2(struct int_frame *frame)
{
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irq3(struct int_frame *frame)
{
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irq4(struct int_frame *frame)
{
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irq5(struct int_frame *frame)
{
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irq6(struct int_frame *frame)
{
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irq7(struct int_frame *frame)
{
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irq8(struct int_frame *frame)
{
	outb(0xa0, 0x20);
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irq9(struct int_frame *frame)
{
	outb(0xa0, 0x20);
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irqa(struct int_frame *frame)
{
	outb(0xa0, 0x20);
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irqb(struct int_frame *frame)
{
	outb(0xa0, 0x20);
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irqc(struct int_frame *frame)
{
	outb(0xa0, 0x20);
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irqd(struct int_frame *frame)
{
	outb(0xa0, 0x20);
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irqe(struct int_frame *frame)
{
	outb(0xa0, 0x20);
	outb(0x20, 0x20);
}

__attribute__((interrupt))
void irqf(struct int_frame *frame)
{
	outb(0xa0, 0x20);
	outb(0x20, 0x20);
}
