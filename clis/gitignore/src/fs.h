#ifndef FILESYSTEM
#define FILESYSTEM

#include <stdbool.h>
#include <dirent.h>

bool dir_exists(const char *path);

typedef struct dirent fs_entry;

typedef bool (* find_fs_entry_predicate)(fs_entry *);

fs_entry *find_fs_entry(find_fs_entry_predicate predicate, DIR *dirp);

#endif
