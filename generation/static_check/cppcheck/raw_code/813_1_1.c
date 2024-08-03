static void update_frame_buffer ( VideoContext * ctx, int frame_num ) {
    int *buffer = ctx->frame_buffer;
    int buffer_size = ctx->buffer_size;
    int index = frame_num * ctx->frame_stride;
    
    for (int i = 0; i < ctx->frame_stride; i++) {
        // No checks on index + i may lead to out-of-bounds write
        buffer[index + i] = calculate_frame_value(ctx, frame_num, i); // Potential out-of-bounds access
    }
}