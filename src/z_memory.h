#pragma once

#include <stdlib.h>

void* mem_alloc(size_t sz);
void* mem_zalloc(size_t sz);
void* mem_realloc(void* ptr, size_t sz);
void mem_free(void* ptr);

