#include <stdlib.h>

#include "vector.h"
#include "memory.h"
#include "panic.h"
#include "string.h"

#define _VECTOR_STARTING_CAPACITY (16)

vector *vector_new() {
    vector *self = memory_allocate(sizeof(vector));
    self->_capacity = _VECTOR_STARTING_CAPACITY;
    self->_length = 0;
    self->_store = memory_allocate(self->_capacity * sizeof(anything));

    return self;
}

nothing vector_free(vector *self) {
    memory_free(self->_store);
    memory_free(self);
}

nothing vector_add(vector *self, anything element) {
    if (self->_length == self->_capacity) {
        self->_store = memory_reallocate(self->_store, self->_capacity * 2);
    }

    self->_store[self->_length] = element;
    self->_length += 1;
}

anything vector_get(vector *self, size_t index) {
    if (index >= self->_length) {
        // TODO: Add index to error message
        panic("vector", "tried getting an element out of bounds");
    }

    return self->_store[index];
}

size_t vector_length(vector *self) {
    return self->_length;
}
