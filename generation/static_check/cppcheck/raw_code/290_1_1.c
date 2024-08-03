typedef struct _buffer {
    char *data;
    size_t length;
} buffer, *bufferPtr;

bufferPtr bufferCreate(size_t initialSize) {
    bufferPtr buf;

    buf = (bufferPtr)malloc(sizeof(buffer));
    if (!buf) {
        perror("Memory allocation failed for buffer structure");
        return NULL;
    }

    buf->data = (char *)malloc(initialSize);
    if (!buf->data) {
        perror("Memory allocation failed for buffer data");
        free(buf); // Potential memory leak if there are other already allocated resources
        return NULL;
    }

    buf->length = initialSize;

    // More initialization code here...

    return buf;
}