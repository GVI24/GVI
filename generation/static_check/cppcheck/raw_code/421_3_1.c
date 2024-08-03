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
void appendStringWithLimit(PQExpBuffer *buf, const char *str, int limit) {
    while (*str && limit > 0) {
        appendPQExpBufferChar(buf, *str);
        str++;
        limit--;
    }
}
