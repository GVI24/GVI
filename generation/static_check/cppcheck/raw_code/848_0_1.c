void encode_video_frame(int frame, int num_blocks, TX_SIZE tx_size, ENCODER *enc) {
    int i;
    int *block_array = malloc(num_blocks * sizeof(int));
    for (i = 0; i <= num_blocks; i++) { // Off-by-one error leading to buffer overflow
        block_array[i] = encode_block(frame, i, tx_size, enc);
    }
    free(block_array);
}

