#include "z_memory.h"

#include <string.h>
#include "log.h"


#define SZ(uptr) *((size_t *)((char *)(uptr) - sizeof(size_t)))

void* mem_alloc(size_t sz) {
	char* mem;

	if(sz == 0) return NULL;

	mem = malloc(sz + sizeof(size_t));
	if(!mem) {
		YON_log_fatal("Out of memory!");
		exit(EXIT_FAILURE);
	}

	mem += sizeof(size_t);
#if defined(MEM_POISON_ALLOC)
	memset(mem, 0xCC, sz);
#endif
	SZ(mem) = sz;
	return mem;
}

void* mem_zalloc(size_t sz) {
	void* mem = mem_alloc(sz);

	if(sz) {
		memset(mem, 0, sz);
	}
	return mem;
}

void mem_free(void* ptr) {
	if(!ptr) return;

#if defined(MEM_POISON_FREE)
	memset(ptr, 0xCD, SZ(ptr));
#endif
	free((char*)ptr - sizeof(size_t));
}

void* mem_realloc(void* ptr, size_t sz) {
	char *mem = ptr;
	if(sz == 0) return NULL;

	mem = realloc(mem ? mem - sizeof(size_t) : NULL, sz + sizeof(size_t));
	mem += sizeof(size_t);

	if(!mem) {
		YON_log_fatal("Out of memory!");
		exit(EXIT_FAILURE);

	}

	SZ(mem) = sz;
	return mem;
}


