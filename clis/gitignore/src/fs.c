#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#include "fs.h"

bool dir_exists(const char *path) {
    DIR *directory = opendir(path);

    bool exists = false;

    if (directory != NULL) {
        // TODO: Check directory type
        exists = true;
        closedir(directory);
    }

    return exists;
}

fs_entry *find_fs_entry(find_fs_entry_predicate predicate, DIR *dirp) {
    // TODO: make recursive
    fs_entry *entry = readdir(dirp);

    while (entry != NULL) {
        if (predicate(entry)) {
            return entry;
        }

        entry = readdir(dirp);
    }

    return NULL;
}
