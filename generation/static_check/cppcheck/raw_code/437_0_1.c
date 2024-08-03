typedef struct {
    char *data;
    int length;
} Buffer;

Buffer *createBuffer(int size) {
    Buffer *buffer = (Buffer *)malloc(sizeof(Buffer));
    if (buffer == NULL) {
        perror("createBuffer: malloc failed");
        return NULL;
    }
    buffer->data = (char *)malloc(size);
    if (buffer->data == NULL) {
        perror("createBuffer: malloc failed for data");
        // Memory leak: 'buffer' struct is not freed before returning.
        return NULL;
    }
    buffer->length = size;
    return buffer;
}