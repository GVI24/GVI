#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_BUFFER 2048

char *read_file_contents(const char *filename) {
    FILE *file;
    struct stat file_stat;
    char *file_buffer;
    
    if (stat(filename, &file_stat) != 0) {
        return NULL;
    }
    
    // Vulnerability: Buffer may be too small for large files
    file_buffer = malloc(MAX(MAX_BUFFER, file_stat.st_size + 1));
    
    file = fopen(filename, "r");
    if (!file) {
        free(file_buffer);
        return NULL;
    }
    
    // Potential overflow if file size exceeds MAX_BUFFER
    fread(file_buffer, 1, file_stat.st_size, file);

    fclose(file);
    file_buffer[file_stat.st_size] = '\0'; // Null-terminate
    return file_buffer;
}