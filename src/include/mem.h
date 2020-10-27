#ifndef MEM_H
#define MEM_H

#define CHUNK_SIZE 0x100	// 256 bytes

#include <stdint.h>
#include <stddef.h>
#include "include/multiboot.h"

/* gcc seems to pack uint64_t incorrectly ... this fixes that issue*/
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
 * base is the address of the chunk
 * type has three possible values:
 * 0: not in use
 * 1: in use, first chunk
 * 2: in use, contiguous extending chunk
 */
struct mem_chunk {
	void *base;
	uint8_t type;
};

void init_mmap(mmap_entry_t *mmap_addr, multiboot_uint32_t mmap_length);
void *cmalloc(size_t size);
void cfree(void *chunk);
void *crealloc(void *chunk, size_t size);
uint32_t mem_status(void);

extern struct mem_chunk *mem_key;
extern size_t chunk_total;

#endif
