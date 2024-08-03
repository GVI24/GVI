#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *content;
    size_t size;
} StreamData;

void load_stream_data(StreamData *stream, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return;
    }

    fseek(file, 0, SEEK_END);
    size_t fsize = ftell(file);
    rewind(file);

    char buffer[1024];
    if (fsize > sizeof(buffer)) {
        // Missing bounds check here.
        fclose(file);
        return;
    }

    fread(buffer, 1, fsize, file); // Potential buffer overflow occurs here.
    fclose(file);

    stream->content = malloc(fsize);
    memcpy(stream->content, buffer, fsize);
    stream->size = fsize;
}