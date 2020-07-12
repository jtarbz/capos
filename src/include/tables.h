#ifndef TABLES
#define TABLES

#include <stdint.h>

/*
 * wrapper for lgdt, from assembly (tables.S)
 */
extern void flush_gdt(uint32_t);

/*
 * representation of a gdt entry
 */
struct gdt_entry {
	uint16_t limit;		// bits 0-15 of segment limit
	uint16_t base_low;	// bits 0-15 of base
	uint8_t base_mid;	// bits 16-23 of base
	uint8_t access;		// access byte
	uint8_t flags;		// flags (high 4 bits) and 16-19 of limit (low)
	uint8_t base_high;	// bits 24-31 of base
} __attribute__((packed));

/*
 * representation of an idt entry
 */
struct idt_entry {
	uint16_t base_low;	// bits 0-15 of isr addr
	uint16_t selector;	// selector for kernel segment
	uint8_t zero;		// he's always gotta be 0
	uint8_t flags;		// flags!
	uint16_t base_high;	// bits 16-31 of isr addr
} __attribute__((packed));

/*
 * representation of a pointer to a table (gdt or idt)
 */
struct table_ptr {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

void init_gdt(void);
void init_idt(void);
void set_gdt(uint32_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags);
void set_idt(uint8_t index, uint32_t base, uint16_t selector, uint8_t flags);

extern void wrap_lgdt(uint32_t);
extern void wrap_lidt(uint32_t);

#endif
