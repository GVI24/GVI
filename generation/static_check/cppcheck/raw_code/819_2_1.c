typedef struct {
    int *frame_sizes;
    int frames_allocated;
} FrameBuffer;

void finalize_frame_buffer(FrameBuffer *buffer) {
    free(buffer->frame_sizes); // Free memory.
    // Incorrectly accessing freed memory can lead o Undefined behavior.
    buffer->frames_allocated = 0;
    for (int i = 0; i < buffer->frames_allocated; i++) {
        buffer->frame_sizes[i] = 0; // Use after free.
    }
}