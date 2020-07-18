#include <stdint.h>
#include "include/util.h"
#include "include/tables.h"
#include "include/isr.h"

struct gdt_entry gdt_entries[3];
struct table_ptr *gdtp;
struct idt_entry idt_entries[256];
struct table_ptr *idtp;

void init_gdt(void)
{
	gdtp->limit = (sizeof(struct gdt_entry) * 3) - 1;
	gdtp->base = (uint32_t)gdt_entries;

	memset(&gdt_entries, 0, sizeof(struct gdt_entry) * 3);

	set_gdt(0, 0, 0, 0, 0);			// null segment
	set_gdt(1, 0, 0xffffffff, 0x9a, 0xcf);	// code
	set_gdt(2, 0, 0xffffffff, 0x92, 0xcf);	// data

	wrap_lgdt((uint32_t)gdtp);
	return;
}

void init_idt(void)
{
	idtp->limit = (sizeof(struct idt_entry) * 256) - 1;
	idtp->base = (uint32_t)idt_entries;

	memset(&idt_entries, 0, sizeof(struct idt_entry) * 256);

	outb(0x20, 0x11);	// begin pic remap initialization
	outb(0xa0, 0x11);
	outb(0x21, 0x20);	// master pic offset
	outb(0xa1, 0x28);	// slave pic offset
	outb(0x21, 0x04);	// inform master of slave at irq2
	outb(0xa1, 0x02);	// inform slave of its identity
	outb(0x21, 0x01);
	outb(0xa1, 0x01);
	outb(0x21, 0x0);
	outb(0xa1, 0x0);

	/* register exceptions */
	set_idt(0x0, (uint32_t)int0, 0x08, 0x8e);
	set_idt(0x1, (uint32_t)int1, 0x08, 0x8e);
	set_idt(0x2, (uint32_t)int2, 0x08, 0x8e);
	set_idt(0x3, (uint32_t)int3, 0x08, 0x8e);
	set_idt(0x4, (uint32_t)int4, 0x08, 0x8e);
	set_idt(0x5, (uint32_t)int5, 0x08, 0x8e);
	set_idt(0x6, (uint32_t)int6, 0x08, 0x8e);
	set_idt(0x7, (uint32_t)int7, 0x08, 0x8e);
	set_idt(0x8, (uint32_t)int8, 0x08, 0x8e);
	set_idt(0x9, (uint32_t)int9, 0x08, 0x8e);
	set_idt(0xa, (uint32_t)inta, 0x08, 0x8e);
	set_idt(0xb, (uint32_t)intb, 0x08, 0x8e);
	set_idt(0xc, (uint32_t)intc, 0x08, 0x8e);
	set_idt(0xd, (uint32_t)intd, 0x08, 0x8e);
	set_idt(0xe, (uint32_t)inte, 0x08, 0x8e);
	set_idt(0x10, (uint32_t)int10, 0x08, 0x8e);
	set_idt(0x11, (uint32_t)int11, 0x08, 0x8e);
	set_idt(0x12, (uint32_t)int12, 0x08, 0x8e);
	set_idt(0x13, (uint32_t)int13, 0x08, 0x8e);
	set_idt(0x14, (uint32_t)int14, 0x08, 0x8e);
	set_idt(0x1e, (uint32_t)int1e, 0x08, 0x8e);

	/* register irqs */
	set_idt(0x20, (uint32_t)irq0, 0x08, 0x8e);
	set_idt(0x21, (uint32_t)irq1, 0x08, 0x8e);
	set_idt(0x22, (uint32_t)irq2, 0x08, 0x8e);
	set_idt(0x23, (uint32_t)irq3, 0x08, 0x8e);
	set_idt(0x24, (uint32_t)irq4, 0x08, 0x8e);
	set_idt(0x25, (uint32_t)irq5, 0x08, 0x8e);
	set_idt(0x26, (uint32_t)irq6, 0x08, 0x8e);
	set_idt(0x27, (uint32_t)irq7, 0x08, 0x8e);
	set_idt(0x28, (uint32_t)irq8, 0x08, 0x8e);
	set_idt(0x29, (uint32_t)irq9, 0x08, 0x8e);
	set_idt(0x2a, (uint32_t)irqa, 0x08, 0x8e);
	set_idt(0x2b, (uint32_t)irqb, 0x08, 0x8e);
	set_idt(0x2c, (uint32_t)irqc, 0x08, 0x8e);
	set_idt(0x2d, (uint32_t)irqd, 0x08, 0x8e);
	set_idt(0x2e, (uint32_t)irqe, 0x08, 0x8e);
	set_idt(0x2f, (uint32_t)irqf, 0x08, 0x8e);

	wrap_lidt((uint32_t)idtp);

	asm volatile ("sti");
	return;
}

void set_gdt(uint32_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags)
{
	gdt_entries[index].limit 	= (limit & 0xffff);	// first part
	gdt_entries[index].flags 	= (limit >> 16) & 0xf;	// end limit
	gdt_entries[index].flags 	|= flags & 0xf0;	// flags
	gdt_entries[index].access 	= access;
	gdt_entries[index].base_low	= (base & 0xffff);	// broken up
	gdt_entries[index].base_mid	= (base >> 16) & 0xff;
	gdt_entries[index].base_high	= (base >> 24) & 0xff;
	return;

}

void set_idt(uint8_t index, uint32_t base, uint16_t selector, uint8_t flags)
{
	idt_entries[index].selector	= selector;
	idt_entries[index].zero		= 0;
	idt_entries[index].flags	= flags;
	idt_entries[index].base_low	= base & 0xffff;
	idt_entries[index].base_high	= (base >> 16) & 0xffff;
	return;
}
