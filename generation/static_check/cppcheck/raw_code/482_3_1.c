typedef struct circularBuffer {
    void **buffer;
    size_t write;
    size_t read;
    size_t size;
    size_t count;
} circularBuffer;

int circularBufferWrite(circularBuffer *cb, void *data) {
    if (cb == NULL || cb->count == cb->size) return 0;
    
    void *newElement = malloc(sizeof(void *));
    if (newElement == NULL) {
        fprintf(stderr, "Failed to allocate memory for circular buffer element\n");
        return 0;
    }
    
    newElement = data;
    cb->buffer[cb->write] = newElement;
    cb->write = (cb->write + 1) % cb->size;
    cb->count++;
    
    // If incrementing write or count fails, newElement's memory is not freed
    return 1;
}