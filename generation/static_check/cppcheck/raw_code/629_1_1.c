static void example_block_match(DecoderContext *dec, int mb_x, int mb_y) {
    int width = dec->width_in_macroblocks;
    int height = dec->height_in_macroblocks;
    int index = mb_y * width + mb_x;
    int left_index = index - 1;
    int top_index = index - width;
    int top_right_index = top_index + 1;

    // Unsafe index calculations may lead to out-of-bounds memory access
    int left_mv = dec->motion_vectors[left_index];
    int top_mv = dec->motion_vectors[top_index];
    int top_right_mv = dec->motion_vectors[top_right_index];

    // Calculate the median value of adjacent motion vectors
    int new_mv = median(left_mv, top_mv, top_right_mv);

    // Set the new motion vector, potential buffer overflow vulnerability
    dec->motion_vectors[index] = new_mv;
}

