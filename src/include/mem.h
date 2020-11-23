#ifndef MEM_H
#define MEM_H

#define CHUNK_SIZE 0x100	// 256 bytes

#include <stdint.h>
#include <stddef.h>
#include "include/multiboot.h"

/* gcc seems to pack uint64_t incorrectly ... this fixes that issue */
struct split_mmap_entry {
	multiboot_uint32_t size;
	multiboot_uint32_t base_addr_low;
	multiboot_uint32_t base_addr_high;
	multiboot_uint32_t length_low;
	multiboot_uint32_t length_high;
	multiboot_uint32_t type;
} __attribute__((packed));
typedef struct split_mmap_entry mmap_entry_t;

/* 
 * structure to keep track of free memory regions.
 * a linked list of these bad boys is maintained starting
 * at free_origin; malloc and free functions remove, split,
 * and re-add free hops
 */
struct free_hop {
	size_t size;
	struct free_hop *fw;
	struct free_hop *bk;
};

/*
 * structure to bind the data of allocated memory together
 * in a cohesive fashion. this acts as a header, and is
 * recovered when a memory region is freed
 */
struct busy_hop {
	size_t size;
	void *data;
};

void init_mmap(mmap_entry_t *mmap_addr, multiboot_uint32_t mmap_length);
void *cmalloc(size_t size);
void cfree(void *mem);
void *crealloc(void *mem, size_t size);
uint32_t mem_status(void);

extern struct free_hop free_origin;
extern size_t mem_total;

#endif
