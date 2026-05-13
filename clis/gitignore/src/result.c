#include <string.h>
#include <stdlib.h>

#include "result.h"
#include "string.h"
#include "panic.h"


result *result_new() {
    result *self = malloc(sizeof(result));
    if (self == NULL) {
        panic("result", "failed to allocate memory");
    }

    self->success = false;
    self->message = string_new();

    return self;
}

void result_set(result *self, bool success, const char *message) {
    self->success = success;
    string_set(self->message, message);
}

void result_free(result *self) {
    string_free(self->message);
    free(self);
}
