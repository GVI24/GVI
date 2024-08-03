static int decode_motion_vector(MpegContext *ctx) {
    unsigned char vector_val;
    int dx, dy;

    vector_val = bytestream2_get_byte(&ctx->bitstream);

    if (vector_val > 127) {
        dx = (vector_val - 128) % 9;
        dy = (vector_val - 128) / 9;
    } else {
        dx = vector_val % 9;
        dy = vector_val / 9;
    }

    printf("Vector value: %d, (dx, dy): (%d, %d)\n", vector_val, dx, dy);
    
    // Attempting to access a frame buffer with potentially out-of-bounds indices
    return access_frame_buffer(ctx, dx - 10, dy - 10);
}
