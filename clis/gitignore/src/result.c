#include "result.h"

#include <string.h>

void result_init(result *self) {
    self->success = false;
    self->message[0] = '\0';
}

void result_set(result *self, bool success, char *message) {
    self->success = success;
    strncpy(self->message, message, RESULT_MESSAGE_MAX_SIZE);
    self->message[RESULT_MESSAGE_MAX_SIZE] = '\0';
}
