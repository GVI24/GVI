void release_frame_context(MpegEncContext **ctx) {
    free(*ctx);
    
    // Vulnerability: Use-After-Free by accessing the pointer after it's been freed
    printf("Frame number: %d\n", (*ctx)->picture_number);
    
    // Proper way would be to set the pointer to NULL after freeing it
    // *ctx = NULL;
}

// Usage Example:
// MpegEncContext *context = malloc(sizeof(MpegEncContext));
// release_frame_context(&context); // Accesses a freed memory