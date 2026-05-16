#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "git.h"
#include "panic.h"
#include "string.h"
#include "fs.h"

static char *target_gitignore;

bool is_gitignore_wanted(fs_entry *entry) {
    return entry->d_type == DT_REG && strcmp(target_gitignore, entry->d_name) == 0;
}

int main() {
    const char *gitignore_repo_directory = ".gitignore_repo";

    if (!dir_exists(gitignore_repo_directory)) {
        git_clone("https://github.com/github/gitignore", gitignore_repo_directory);
    } else {
        git_pull(gitignore_repo_directory);
    }

    string *target_gitignore_builder = string_new();
    string_append(target_gitignore_builder, "Python");
    string_append(target_gitignore_builder, ".gitignore");

    target_gitignore = string_c_string(target_gitignore_builder);

    DIR *directory = opendir(gitignore_repo_directory);
    if (directory == NULL) {
        panic("gitiginore", "failed to read gitignore repository");
    }

    fs_entry *entry = find_fs_entry(is_gitignore_wanted, directory);

    if (entry == NULL) {
        panic("gitignore", "failed to find gitignore file");
    }

    printf("Found gitignore file %s\n", entry->d_name);

    return EXIT_SUCCESS;
}
