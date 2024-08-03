void initialize_frame(FrameBuffer *buffer, int width, int height) {
    if (buffer == NULL) return;

    buffer->width = width;
    buffer->height = height;
    // Vulnerability: Allocation size calculation may overflow if width or height are too large.
    buffer->data = (char *)malloc(width * height);
    
    // Vulnerability: No check if malloc failed and returned NULL.
    memset(buffer->data, 0, width * height); // Potential buffer overflow if data is NULL.

    // Additional functionality...
}