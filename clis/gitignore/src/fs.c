#include <stdlib.h>
#include <stdbool.h>

#include <sys/types.h>
#include <dirent.h>

#include "fs.h"

bool dir_exists(const char *path) {
    DIR *directory = opendir(path);

    bool exists = false;

    if (directory != NULL) {
        exists = true;
        closedir(directory);
    }

    return exists;
}
