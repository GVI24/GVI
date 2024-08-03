static int copy_motion_block(VideoContext *ctx, int block_id) {
    uint8_t *source, *dest;
    int mv_x = ctx->motion_vector[block_id][0];
    int mv_y = ctx->motion_vector[block_id][1];
    source = ctx->current_frame + mv_y * ctx->frame_line_size + mv_x;
    dest = ctx->buffer;

    if (source < ctx->frame_start) {
        fprintf(stderr, "Error: Invalid motion vector, outside of frame boundaries.\n");
        return -1;
    }

    // Vulnerability: no bounds checking on dest buffer
    memcpy(dest, source, 4);  // Assume we want to copy 4 bytes

    return 0;
}
