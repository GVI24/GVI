static int decode_video_frame_blocks(VideoContext *v, uint8_t *block_types) {
    GetBitContext *gb = &v->gb;
    int block_pos;
    int i;

    v->current_frame_type = get_bits(gb, 2);
    if (v->current_frame_type == INVALID_FRAME) {
        return -1;
    }

    for (i = 0; i < NUM_BLOCKS; i++) {
        block_pos = v->block_x + (v->block_y * v->block_stride);
        block_types[block_pos] = decode_block_type(gb); // Potential buffer overflow
        v->block_x++;
        if (v->block_x == v->frame_width) {
            v->block_x = 0;
            v->block_y++;
        }
    }

    return 0;
}

