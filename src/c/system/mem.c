#include <stddef.h>
#include "include/multiboot.h"
#include "include/mem.h"
#include "include/util.h"

struct mem_chunk *mem_key;	// global, list of chunks and their states
size_t chunk_total;		// set in mmap_init()

void init_mmap(mmap_entry_t *mmap_addr, multiboot_uint32_t mmap_length)
{
	mmap_entry_t *entry = mmap_addr;
	size_t available_regions = 0;
	size_t mem_total = 0;

	/* make space for all regions to have enough for available regions */
	mmap_entry_t *available_mem[mmap_length / sizeof(mmap_entry_t)];

	/* iterate through memory regions, keeping track of available space */
	while (entry < mmap_addr + mmap_length) {
		if (entry->type == 1 && entry->base_addr_low >= 0x100000) {
			available_mem[available_regions] = entry;
			++available_regions;
		}

		entry = (mmap_entry_t *) ((unsigned int) entry + entry->size +
					                  sizeof(entry->size));
	}

	/* find the total amount of memory available */
	for (size_t i = 0; i < available_regions; ++i)
		mem_total += available_mem[i]->length_low;

	chunk_total = mem_total / CHUNK_SIZE;

	/* find available region with space for chunk data, then fill it in */
	size_t k = 0;
	size_t l = 0;
	for (size_t i = 0; i < available_regions; ++i) {
		if (available_mem[i]->length_low >= (chunk_total * sizeof(struct mem_chunk))) {
			mem_key = available_mem[i]->base_addr_low;

			for (size_t j = 0; j < chunk_total; ++j) {
				mem_key[j].base = available_mem[k]->base_addr_low + (CHUNK_SIZE * l);
				mem_key[j].type = 0;
				++l;

				if (available_mem[k]->base_addr_low + (CHUNK_SIZE * l) >
				    available_mem[k]->base_addr_low + available_mem[k]->length_low) {
					++k;
					l = 0;
				}
			}

			break;
		}
	}

	/* mark metadata chunks as type 1 */
	for (size_t i = 0; i < ((chunk_total * sizeof(struct mem_chunk)) / 0x1000) + 0x1000 ; ++i)
		mem_key[i].type = 1;
}

void *cmalloc(size_t size)
{
	if (size < CHUNK_SIZE) {
		for (size_t i = 0; i < chunk_total; ++i) {
			if (mem_key[i].type == 0) {
				mem_key[i].type = 1;
				return mem_key[i].base;
			}
		}
	}
	else {
		for (size_t i = 0; i < chunk_total; ++i) {
			for (size_t j = 0; ; ++j) {
				if (mem_key[i + j].type != 0) {
					break;
				}
				else if (j == (size / CHUNK_SIZE)) {
					for (j; j > 0; --j)
						mem_key[i + j].type = 2;
					
					mem_key[i].type = 1;
					return mem_key[i].base;
				}
			}

		}
	}

	return NULL;	// memory machine broke
}

void cfree(void *chunk)
{
	for (size_t i = 0; i < chunk_total; ++i) {
		if ((void *)mem_key[i].base == chunk) {
			mem_key[i].type = 0;
			for (size_t j = 1; mem_key[i + j].type == 2; ++j)
				mem_key[i + j].type = 0;

			return;
		}
	}
}

void *crealloc(void *chunk, size_t size)
{
	void *nchunk = cmalloc(size);
	memcpy(nchunk, chunk, size);
	cfree(chunk);
	return(nchunk);
}
