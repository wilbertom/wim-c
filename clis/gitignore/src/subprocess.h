#ifndef SUBPROCESS
#define SUBPROCESS

#include <stdint.h>
#include <stdio.h>

#include "./string.h"
#include "./result.h"

typedef struct subprocess {
    FILE *_fp;
    string *output;
    result *result;
    int32_t _status;
} subprocess;

subprocess *subprocess_run(const char *command);

void subprocess_free(subprocess *self);

uint32_t subprocess_status(subprocess *self);

#endif
