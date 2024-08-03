static void test_evbuffer_overflow_4() {
    const size_t bufsize = 128;
    char data[bufsize];
    struct evbuffer *buf = evbuffer_new();

    strcpy(data, "Header:");  // Properly null-terminated
    for (size_t i = strlen("Header:"); i < bufsize; i++) {
        data[i] = 'e';  // No null-terminator set for data
    }

    evbuffer_add(buf, data, strlen(data));  // Relies on null-termination, which is missing
    // ... (omitted code for brevity)
    evbuffer_free(buf);
}



// Stub implementations for evbuffer functions
evbuffer *evbuffer_new() {
    evbuffer *buffer = malloc(sizeof(evbuffer));
    buffer->capacity = 256;
    buffer->length = 0;
    buffer->buffer = malloc(buffer->capacity);
    return buffer;
}

void evbuffer_free(evbuffer *buffer) {
    free(buffer->buffer);
    free(buffer);
}

int evbuffer_add(evbuffer *buffer, const char *data, size_t datalen) {
    if (buffer->length + datalen > buffer->capacity) return -1;
    memcpy(buffer->buffer + buffer->length, data, datalen);
    buffer->length += datalen;
    return 0;
}

int evbuffer_drain(evbuffer *buffer, size_t datalen) {
    if (datalen > buffer->length) return -1;
    memmove(buffer->buffer, buffer->buffer + datalen, buffer->length - datalen);
    buffer->length -= datalen;
    return 0;
}

char *evbuffer_search(evbuffer *buffer, const char *what, size_t len) {
    for (size_t i = 0; i <= buffer->length - len; i++) {
        if (memcmp(buffer->buffer + i, what, len) == 0) {
            return buffer->buffer + i;
        }
    }
    return NULL;
}