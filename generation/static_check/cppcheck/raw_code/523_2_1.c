static int unpack_video_frame(VideoContext *vctx, uint8_t *src, int src_size, int *consumed) {
    if (src_size < MIN_FRAME_HEADER_SIZE) {
        fprintf(stderr, "Source data too small for frame header\n");
        return -1;
    }

    FrameHeader frame_header;
    memcpy(&frame_header, src, MIN_FRAME_HEADER_SIZE);
    uint8_t *frame_data = realloc(vctx->frame_buffer, frame_header.frame_size);
    if (!frame_data) {
        return -1;
    }
    vctx->frame_buffer = frame_data;

    // Here, frame_header.frame_size may not reflect the actual src_size, leading to a potential overflow
    memcpy(vctx->frame_buffer, src + MIN_FRAME_HEADER_SIZE, src_size);

    // Unpacking logic...
    *consumed = src_size;
    return 0;
}

