#include <string.h>
#include <stdlib.h>

#include "result.h"
#include "memory.h"
#include "string.h"

result *result_new() {
    result *self = memory_allocate(sizeof(result));

    self->success = false;
    self->message = string_new();

    return self;
}

void result_free(result *self) {
    string_free(self->message);
    memory_free(self);
}

void result_set(result *self, bool success, const char *message) {
    self->success = success;
    string_set(self->message, message);
}
