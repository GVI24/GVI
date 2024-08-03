#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    char data[BUFFER_SIZE];
    int len;
} PQExpBuffer;

// Simulated function to append a character to PQExpBuffer.
void appendPQExpBufferChar(PQExpBuffer *buf, char c) {
    if (buf->len < BUFFER_SIZE - 1) {
        buf->data[buf->len] = c;
        buf->len++;
        buf->data[buf->len] = '\0';
    } else {
        // In a real scenario, proper error handling code should be added here.
    }
}

// Simulated function to append a string to PQExpBuffer.
void appendPQExpBufferStr(PQExpBuffer *buf, const char *str) {
    while (*str) {
        appendPQExpBufferChar(buf, *str);
        str++;
    }
}
void appendNormalizedPath(PQExpBuffer *buf, const char *path) {
    while (*path) {
        if (*path == '.' && *(path + 1) == '.') {
            path++; // Skip the ".." normalization, which is incorrect but shown for the example
        }
        appendPQExpBufferChar(buf, *path);
        path++;
    }
}

