#include <stddef.h>
#include <stdint.h>
#include "include/multiboot.h"
#include "include/mem.h"
#include "include/printf.h"
#include "include/util.h"

struct free_hop free_origin;	// global, head of free hop list
size_t mem_total;		// set in mmap_init()

void init_mmap(mmap_entry_t *mmap_addr, multiboot_uint32_t mmap_length)
{
	mmap_entry_t *entry = mmap_addr;
	size_t available_regions = 0;
	mem_total = 0;

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

	for (size_t i = 0; i < available_regions; ++i) {
		if (available_mem[i]->length_low >= 0x100000) {
			free_origin.fw = (struct free_hop *)available_mem[i]->base_addr_low;
			free_origin.size = 0;
			free_origin.bk = NULL;

			free_origin.fw->size = (size_t)available_mem[i]->length_low;
			free_origin.fw->fw = NULL;
			free_origin.fw->bk = &free_origin;
			mem_total += available_mem[i]->length_low;
			break;
		}
	}

	return;
}

void *cmalloc(size_t size)
{
	struct free_hop *p = free_origin.fw;
	size = (size + sizeof(struct busy_hop) + 7) & (-8);

	/* if there is a memory region of equal size, pop out and fix links */
	while (p != NULL) {
		if (p->size == size) {
			p->bk->fw = p->fw;
			if (p->fw != NULL)
				p->fw->bk = p->bk;
			struct busy_hop *busy = (struct busy_hop *)p;
			busy->size = size;
			return &(busy->data);
		}

		p = p->fw;
	}

	/* otherwise, split the first larger region */
	p = free_origin.fw;
	while (p != NULL) {
		/* if size is greater, carve out space and fix links */
		if (p->size - sizeof(struct free_hop) > size) {
			p->bk->fw = (struct free_hop *)((char *)p + size);
			p->bk->fw->bk = p->bk;
			p->bk->fw->fw = p->fw;
			p->bk->fw->size = (p->size - size);
			if (p->fw != NULL)
				p->fw->bk = p->bk->fw;
			struct busy_hop *busy = (struct busy_hop *)p;
			busy->size = size;
			return &(busy->data);
		}

		/* if size is less, proceed to next link in chain */
		p = p->fw;
	}

	return NULL;	// memory machine broke
}

void cfree(void *mem)
{
	/* reassemble busy hop structure and yoink memory region size */
	struct busy_hop *busy = (struct busy_hop *)((char *)mem - offsetof(struct busy_hop, data));
	size_t size = busy->size;

	/* recast to free hop structure and link to beginning of chain */
	struct free_hop *p = (struct free_hop *)busy;
	p->size = size;
	struct free_hop *tmp = free_origin.fw;
	free_origin.fw = p;
	p->bk = &free_origin;
	p->fw = tmp;
	tmp->bk = p;
	return;
}

void *crealloc(void *mem, size_t size)
{
	void *nmem = cmalloc(size);
	memcpy(nmem, mem, size);
	cfree(mem);
	return nmem;
}

size_t mem_status(void)
{
	struct free_hop *p = free_origin.fw;
	size_t free = 0;

	while (p != NULL) {
		free += p->size;
		p = p->fw;
	}

	return free;
}

void defragment(void)
{
	struct free_hop *p = free_origin.fw;
	struct free_hop *cmp = p->fw;

	/* search for adjacent hops, then collapse them together */
	while (p != NULL) {
		while (cmp != NULL) {
			if (cmp == (struct free_hop *)((char *)p + p->size)) {
				cmp->bk->fw = cmp->fw;
				if (cmp->fw != NULL)
					cmp->fw->bk = cmp->bk;
				p->size = (p->size + cmp->size);
			}

			cmp = cmp->fw;
		}

		p = p->fw;
		cmp = free_origin.fw;
	}

	return;
}

