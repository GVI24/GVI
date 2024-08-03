static int decode_video_frame(DecodeContext *dctx, int vector_index) {
    uint8_t *frame_start;
    frame_start = dctx->frame_buf + dctx->motion_vectors[vector_index].x +
                  dctx->motion_vectors[vector_index].y * dctx->line_size;

    if (frame_start < dctx->frame_buf) {
        printf("Decode error: Motion vector points to invalid location.\n");
        return -1;
    }

    // Vulnerability: possible buffer overflow when writing to dctx->decode_buf
    for (int i = 0; i < 2; i++) {
        dctx->decode_buf[i] = frame_start[i];
        dctx->decode_buf[dctx->line_size + i] = frame_start[dctx->line_size + i];
    }

    return 0;
}
