#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file_into_buffer(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(filesize + 1);
    if (fread(buffer, filesize, 1, file) < 1) {
        // Memory leak: buffer is not freed if fread fails
        fclose(file);
        return NULL;
    }

    buffer[filesize] = '\0'; // could be wrong if filesize is larger than buffer size
    fclose(file);
    return buffer;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file_contents = read_file_into_buffer(argv[1]);
    if (file_contents) {
        printf("File contents: %s\n", file_contents);
    } else {
        fprintf(stderr, "Failed to read file\n");
    }

    free(file_contents);
    return EXIT_SUCCESS;
}

