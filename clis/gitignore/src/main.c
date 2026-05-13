#include <stdlib.h>
#include <stdio.h>

#include "git.h"
#include "fs.h"

int main() {
    const char *gitignore_repo_directory = ".gitignore_repo";

    if (!dir_exists(gitignore_repo_directory)) {
        git_clone("https://github.com/github/gitignore", gitignore_repo_directory);
    } else {
        git_pull(gitignore_repo_directory);
    }

    return EXIT_SUCCESS;
}
