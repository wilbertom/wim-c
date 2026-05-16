#include "memory.h"
#include "panic.h"
#include <stdlib.h>

memory memory_allocate(size_t size) {
    memory self = malloc(size);

    if (self == NULL) {
        panic("memory", "failed to allocate memory");
    }

    return self;
}

memory memory_reallocate(memory self, size_t size) {
    memory new_self = realloc(self, size);

    if (new_self == NULL) {
        panic("memory", "failed to reallocate memory");
    }

    return new_self;
}

void memory_free(memory self) {
    free(self);
}
