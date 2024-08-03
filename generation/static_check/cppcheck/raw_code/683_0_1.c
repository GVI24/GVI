void process_video_frame_1(MpegEncContext *s) {
    int mb_x, mb_y;
    for (mb_x = 0; mb_x < s->mb_width; mb_x++) {
        for (mb_y = 0; mb_y < s->mb_height; mb_y++) {
            int block_index = s->mb_stride * mb_y + mb_x;
            if (block_index >= MAX_BLOCKS) {
                // Ideally, we should handle this error properly.
                printf("Error: Block index out of bounds.\n");
                return;
            }

            // Simulate processing the block
            s->block_data[block_index] = process_block(mb_x, mb_y);

            // Incorrectly increment block_index, could lead to buffer overflow
            block_index += 10;
        }
    }
}

