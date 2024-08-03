void motion_estimation(MotionVector *m_vectors, ImageBlock *ref_block, Frame *curr_frame) {
    int block_size = 16; // Example block size for motion estimation.
    for (int y = 0; y < curr_frame->height; y += block_size) {
        for (int x = 0; x < curr_frame->width; x += block_size) {
            ImageBlock current_block;
            // Vulnerability: No bounds checking when accessing curr_frame->data.
            get_image_block(&current_block, curr_frame, x, y, block_size); // Potential buffer overread.
            MotionVector mv = find_best_match(&current_block, ref_block);
            store_motion_vector(m_vectors, x, y, &mv);
        }
    }
}

void get_image_block(ImageBlock *block, Frame *frame, int x, int y, int block_size) {
    // Vulnerability: Assumes that get_image_block is always called with valid x, y, and block_size.
    for (int i = 0; i < block_size; i++) {
        for (int j = 0; j < block_size; j++) {
            block->data[i * block_size + j] = frame->data[(y + i) * frame->width + (x + j)];
        }
    }
}