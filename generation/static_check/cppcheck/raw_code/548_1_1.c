typedef struct {
    uint8_t *data;
} Frame;

void process_frame(Frame *frame, int should_free) {
    Frame copy;
    // Dynamically allocate memory for frame copy.
    copy.data = malloc(1024 * 768 * sizeof(uint8_t));
    
    // Perform some processing on copy (omitted for brevity).
    
    if (should_free) {
        free(frame->data); // The original frame data is freed.
    }

    // Use-after-free vulnerability: using the original frame data after it's been freed.
    frame->data[0] = copy.data[0]; // <- Accessing potentially freed memory.
    
    free(copy.data);
}