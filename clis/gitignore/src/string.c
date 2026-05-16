#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./string.h"
#include "./memory.h"

#define _STRING_INITIAL_CAPACITY (32)

void _string_malloc_store(string *self, size_t capacity) {
    self->_length = 0;
    self->_capacity = capacity;

    self->_store = memory_allocate(self->_capacity + 1);
    self->_store[0] = '\0';
    self->_store[self->_capacity] = '\0';
}

void _string_fit_capacity(string *self, size_t length) {
    bool changed_capacity = false;
    while (length > self->_capacity) {
        self->_capacity = self->_capacity * 2;
        changed_capacity = true;
    }

    if (changed_capacity) {
        self->_store = memory_reallocate(self->_store, self->_capacity + 1);

        self->_store[self->_capacity] = '\0';
    }
}

string *string_new() {
    string *self = memory_allocate(sizeof(string));

    _string_malloc_store(self, _STRING_INITIAL_CAPACITY);

    return self;
}

void string_free(string *self) {
    memory_free(self->_store);
    memory_free(self);
}

void string_set(string *self, const char *s) {
    size_t s_length = strlen(s);

    _string_fit_capacity(self, s_length);

    self->_length = s_length;
    memcpy(self->_store, s, self->_length);
    self->_store[self->_length] = '\0';
}

void string_append(string *self, const char *s) {
    size_t s_length = strlen(s);
    size_t new_length = self->_length + s_length;

    _string_fit_capacity(self, new_length);

    self->_length = new_length;
    strncat(self->_store, s, s_length);
}

const char *string_c_string(string *self) {
    return self->_store;
}

size_t string_length(string *self) {
    return self->_length;
}
