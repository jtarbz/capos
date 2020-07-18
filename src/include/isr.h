#ifndef ISR_H
#define ISR_H

#include "include/printf.h"
#include "include/vga.h"

#include <stdint.h>

/*
 * interrupt frame for when there is no privilege change
 */
struct int_frame {
	uint32_t eflags;
	uint32_t cs;
	uint32_t eip;
	uint32_t err;
};

__attribute__((interrupt)) void int0(struct int_frame *frame);
__attribute__((interrupt)) void int1(struct int_frame *frame);
__attribute__((interrupt)) void int2(struct int_frame *frame);
__attribute__((interrupt)) void int3(struct int_frame *frame);
__attribute__((interrupt)) void int4(struct int_frame *frame);
__attribute__((interrupt)) void int5(struct int_frame *frame);
__attribute__((interrupt)) void int6(struct int_frame *frame);
__attribute__((interrupt)) void int7(struct int_frame *frame);
__attribute__((interrupt)) void int8(struct int_frame *frame);
__attribute__((interrupt)) void int9(struct int_frame *frame);
__attribute__((interrupt)) void inta(struct int_frame *frame);
__attribute__((interrupt)) void intb(struct int_frame *frame);
__attribute__((interrupt)) void intc(struct int_frame *frame);
__attribute__((interrupt)) void intd(struct int_frame *frame);
__attribute__((interrupt)) void inte(struct int_frame *frame);
__attribute__((interrupt)) void int10(struct int_frame *frame);
__attribute__((interrupt)) void int11(struct int_frame *frame);
__attribute__((interrupt)) void int12(struct int_frame *frame);
__attribute__((interrupt)) void int13(struct int_frame *frame);
__attribute__((interrupt)) void int14(struct int_frame *frame);
__attribute__((interrupt)) void int1e(struct int_frame *frame);

__attribute__((interrupt)) void irq0(struct int_frame *frame);
__attribute__((interrupt)) void irq1(struct int_frame *frame);
__attribute__((interrupt)) void irq2(struct int_frame *frame);
__attribute__((interrupt)) void irq3(struct int_frame *frame);
__attribute__((interrupt)) void irq4(struct int_frame *frame);
__attribute__((interrupt)) void irq5(struct int_frame *frame);
__attribute__((interrupt)) void irq6(struct int_frame *frame);
__attribute__((interrupt)) void irq7(struct int_frame *frame);
__attribute__((interrupt)) void irq8(struct int_frame *frame);
__attribute__((interrupt)) void irq9(struct int_frame *frame);
__attribute__((interrupt)) void irqa(struct int_frame *frame);
__attribute__((interrupt)) void irqb(struct int_frame *frame);
__attribute__((interrupt)) void irqc(struct int_frame *frame);
__attribute__((interrupt)) void irqd(struct int_frame *frame);
__attribute__((interrupt)) void irqe(struct int_frame *frame);
__attribute__((interrupt)) void irqf(struct int_frame *frame);

#endif
