static void update_frame_dimensions(FRAME_HANDLER *handler, int new_width, int new_height) {
    // Potential vulnerability: no checks on the validity of new_width and new_height
    handler->current_frame->width = new_width;
    handler->current_frame->height = new_height;

    // Reallocating the buffer with updated dimensions
    unsigned char *new_buffer = realloc(handler->current_frame->data, new_width * new_height);
    if (new_buffer == NULL) {
        error_handler(handler, "Failed to reallocate frame buffer.");
    }
    handler->current_frame->data = new_buffer;

    // ... Additional code to handle the frame data ...
}