#ifndef RESULT
#define RESULT

#include <stdbool.h>

#define RESULT_MESSAGE_MAX_SIZE (255)

typedef struct {
    char message[RESULT_MESSAGE_MAX_SIZE + 1];
    bool success;
} result;

void result_init(result *self);

void result_set(result *self, bool success, char *message);

#endif
