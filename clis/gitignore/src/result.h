#ifndef RESULT
#define RESULT

#include <stdbool.h>

#include "./string.h"

typedef struct {
    bool success;
    string *message;
} result;

result *result_new();
void result_free(result *self);

void result_set(result *self, bool success, const char *message);

#endif
