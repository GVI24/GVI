static int replicate_block_data(EncoderContext *enc, int vector_idx) {
    uint8_t *block_start;
    block_start = enc->encoded_data + enc->block_motion[vector_idx][0] +
                  enc->block_motion[vector_idx][1] * enc->block_line_size;

    // Checking for underflow condition only
    if (block_start < enc->encoded_data) {
        puts("Encoder error: Motion vector out of range.");
        return -3;
    }

    // Vulnerability: blindly copying data can lead to buffer overruns in enc->block_buf
    for (int k = 0; k < 4; k++) {
        enc->block_buf[k * enc->block_line_size] = block_start[k * enc->block_line_size];
    }

    return 0;
}