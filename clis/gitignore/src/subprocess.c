#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "./subprocess.h"
#include "result.h"
#include "panic.h"
#include "memory.h"
#include "string.h"


// TODO: replace result with different negative status codes
#define _SUBPROCESS_NOT_STARTED_STATUS (-1)

#define _SUBPROCESS_BUFFER_SIZE (4096)

void _subprocess_run(subprocess *self, const char *command);

subprocess *subprocess_run(const char *command) {
    subprocess *self = memory_allocate(sizeof(subprocess));

    self->output = string_new();
    self->result = result_new();
    self->_status = _SUBPROCESS_NOT_STARTED_STATUS;

    _subprocess_run(self, command);

    return self;
}

void _subprocess_run(subprocess *self, const char *command) {
    self->_fp = popen(command, "r");

    if (self->_fp == NULL) {
        // TODO: Add strerror(errno)
        result_set(self->result, false, "subprocess - failed to open command");
        return;
    }

    char buffer[_SUBPROCESS_BUFFER_SIZE];
    while (fgets(buffer, _SUBPROCESS_BUFFER_SIZE, self->_fp) != NULL) {
        string_append(self->output, buffer);
    }

    if (ferror(self->_fp)) {
        result_set(self->result, false, "subprocess - failed while reading file");
        return;
    }

    int wait_status = pclose(self->_fp);

    if (wait_status == -1) {
        result_set(self->result, false, "subprocess - failed to close subprocess");
        return;
    }

    if (WIFSIGNALED(wait_status)) {
        result_set(self->result, false, "subprocess - killed by signal");
        return;
    }

    if (WIFEXITED(wait_status)) {
        self->_status = WEXITSTATUS(wait_status);
        result_set(self->result, true, "subprocess - finished");
        return;
    }

    result_set(self->result, false, "subprocess - failed for unknown reason");
    return;
}

void subprocess_free(subprocess *self) {
    result_free(self->result);
    string_free(self->output);
    memory_free(self);
}

uint32_t subprocess_status(subprocess *self) {
    if (self->_status == _SUBPROCESS_NOT_STARTED_STATUS) {
        panic("subprocess", "run not started");
    }

    return self->_status;
}
