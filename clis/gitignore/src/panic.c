#include <stdio.h>
#include <stdlib.h>

#include "./panic.h"

[[noreturn]] void panic(char *name, char *message) {
    fprintf(stderr, "panic %s - %s\n", name, message);
    exit(EXIT_FAILURE);
}
