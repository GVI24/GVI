#include <stdlib.h>
#include <string.h>

typedef struct dir {
    char *name;
    struct dir **subdirs;
    int num_subdirs;
} Dir;

void process_directory(Dir *directory) {
    if (!directory) return;

    // Potential stack overflow if directory depth is too high
    for (int i = 0; i < directory->num_subdirs; i++) {
        process_directory(directory->subdirs[i]);
    }
    // Memory leak: strdup without free
    char *dir_copy = strdup(directory->name);
    printf("Processing: %s\n", dir_copy);
    // Missing free(dir_copy);
}

int main() {
    // Setup directories and call process_directory...
    return 0;
}