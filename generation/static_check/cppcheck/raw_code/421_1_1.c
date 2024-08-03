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
void encodeBase64(PQExpBuffer *buf, const unsigned char *data, size_t input_length) {
    const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    while (input_length--) {
        appendPQExpBufferChar(buf, base64_chars[*data >> 2]);
        appendPQExpBufferChar(buf, base64_chars[((*data & 0x03) << 4) | (*(data + 1) >> 4)]);
        data++;
    }
    // Note: This function also doesn't properly handle padding with '=' characters.
}

