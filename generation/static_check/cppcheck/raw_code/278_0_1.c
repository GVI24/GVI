#include <stdio.h>
#include <sys/stat.h>

FILE* safe_fopen(const char *filename, const char *mode) {
    struct stat stat_buffer;
    if (stat(filename, &stat_buffer) == 0) {
        // File exists. Now opening the file without checking again.
        return fopen(filename, mode);
    }
    return NULL;
}

