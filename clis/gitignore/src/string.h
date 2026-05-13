#ifndef STRING
#define STRING

#include <stddef.h>

typedef struct {
    size_t _capacity;
    size_t _length;
    char *_store;
} string;

void string_init(string *self);
void string_free(string *self);
void string_set(string *self, const char *s);
void string_append(string *self, const char *s);
size_t string_length(string *self);
const char *string_c_string(string *self);

#endif
