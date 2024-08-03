static int unpack_video_frame(VideoContext *vctx, const uint8_t *src, size_t src_size) {
    VideoFrame *frame;
    GetBitContext gb;
    int block_size = vctx->block_size;
    int num_blocks = src_size / block_size;

    if (num_blocks < vctx->min_blocks) {
        fprintf(stderr, "Source buffer too small\n");
        return -1;
    }

    frame = get_video_frame_buffer(vctx);
    if (!frame) {
        return -1;
    }

    for (int i = 0; i < num_blocks; i++) {
        init_get_bits(&gb, &src[block_size * i], block_size * 8);
        if (decode_video_block(vctx, &gb, frame) < 0) {
            release_video_frame_buffer(frame);
            return -1;
        }
    }

    return 0;
}