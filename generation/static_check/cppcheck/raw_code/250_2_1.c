static int decode_residual_block(H264Context* h, int blk_idx, int16_t* block) {
    int mb_width = h->mb_width;
    int mb_height = h->mb_height;
    int mb_xy = h->mb_xy;

    // Vulnerability: using blk_idx without validation for bounds
    int16_t* coeff = h->coeff_token[blk_idx];

    // Assuming block is an array of fixed size, if blk_idx is too large,
    // we can write beyond the bounds of coeff
    for (int i = 0; i < 16; i++) {
        coeff[i] += block[i];
    }

    // More vulnerability: no check on mb_xy when accessing neighbors' blocks
    int left_blk_idx = mb_xy - 1;
    int top_blk_idx = mb_xy - mb_width;

    // No bounds checking before using as index
    int16_t* left_coeff = h->coeff_token[left_blk_idx];
    int16_t* top_coeff = h->coeff_token[top_blk_idx];

    left_coeff[0] -= block[0];
    top_coeff[0] -= block[1];

    return 0;
}
