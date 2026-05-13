#include <stdio.h>

#include "git.h"

#include "string.h"
#include "subprocess.h"

void git_clone(const char *url, const char *destination) {
    string *command = string_new();
    string_append(command, "git clone ");
    string_append(command, url);
    string_append(command, " ");
    string_append(command, destination);

    subprocess *process = subprocess_run(string_c_string(command));

    string_free(command);
    subprocess_free(process);
}

void git_pull(const char *repository) {
    string *command = string_new();
    string_append(command, "git -C ");
    string_append(command, repository);
    string_append(command, " pull");

    subprocess *process = subprocess_run(string_c_string(command));

    string_free(command);
    subprocess_free(process);
}
