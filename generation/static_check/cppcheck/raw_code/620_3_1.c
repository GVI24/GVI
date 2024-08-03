typedef struct {
    char* text;
    size_t size;
} Buffer;

int init_buffer(Buffer *buffer, const char* initial_text) {
    buffer->size = strlen(initial_text);
    buffer->text = (char*)malloc(buffer->size + 1); // Allocation
    if (buffer->text == NULL) {
        return -1; // Memory leak here if not freed
    }
    memcpy(buffer->text, initial_text, buffer->size);
    buffer->text[buffer->size] = '\0';
    // If the buffer needs to be re-initialized, the old buffer->text is not freed
    return 0;
}

void free_buffer(Buffer *buffer) {
    free(buffer->text); // Only way to free memory
    buffer->text = NULL;
    buffer->size = 0;
}