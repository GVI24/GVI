#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_DEFAULT_SIZE 256
#define BUFFER_MAX_LIMIT 1024 * 1024  // 1MB

typedef struct {
    char* buffer;
    size_t size;
    size_t capacity;
} DynamicBuffer;

int bufferAppend(DynamicBuffer* db, const char* data) {
    if (db == NULL || data == NULL) {
        return -1;
    }

    size_t data_len = strlen(data);
    if (db->size + data_len >= db->capacity) {
        size_t new_capacity = db->capacity * 2;
        if (new_capacity > BUFFER_MAX_LIMIT) {
            return -1;  // Maximum size reached, buffer cannot grow further.
        }

        char* new_buffer = realloc(db->buffer, new_capacity);
        if (!new_buffer) {
            return -1;  // Memory allocation failed.
        }

        db->buffer = new_buffer;
        db->capacity = new_capacity;
    }

    memcpy(db->buffer + db->size, data, data_len);
    db->size += data_len;
    return 0;
}

void bufferInit(DynamicBuffer* db) {
    db->buffer = malloc(BUFFER_DEFAULT_SIZE);
    db->size = 0;
    db->capacity = BUFFER_DEFAULT_SIZE;
}

void bufferFree(DynamicBuffer* db) {
    free(db->buffer);
    db->size = 0;
    db->capacity = 0;
}

int main() {
    DynamicBuffer db;
    bufferInit(&db);

    // This loop can cause uncontrolled buffer growth
    while (bufferAppend(&db, "data") == 0) {
        // Potentially infinite loop if BUFFER_MAX_LIMIT is not adequately defined
    }

    bufferFree(&db);
    return 0;
}