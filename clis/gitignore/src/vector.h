#ifndef VECTOR
#define VECTOR

#include <stddef.h>

#include "defs.h"

typedef struct {
    size_t _length;
    size_t _capacity;
    anything *_store;
} vector;

vector *vector_new();
nothing vector_free(vector *self);

nothing vector_add(vector *self, anything element);
anything vector_get(vector *self, size_t index);
size_t vector_length(vector *self);

#endif
