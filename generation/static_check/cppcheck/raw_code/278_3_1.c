#include <stdio.h>

int remove_file_if_exists(const char *path) {
    if (fopen(path, "r") != NULL) {
        // The file exists, but it might not when remove is called
        return remove(path);
    }
    return -1; // File does not exist
}

