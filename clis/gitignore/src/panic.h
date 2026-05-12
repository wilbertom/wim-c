#ifndef PANIC
#define PANIC

#include "./string.h"

[[noreturn]] void panic(char *name, char *message);

#endif
