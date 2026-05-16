#ifndef MEMORY
#define MEMORY

#include <stddef.h>
#include <stdlib.h>

typedef void * memory;

memory memory_allocate(size_t size);
memory memory_reallocate(memory self, size_t size);
void memory_free(memory self);

#endif
