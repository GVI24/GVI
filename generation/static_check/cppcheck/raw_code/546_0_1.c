void decode_intra_frame_block(int x, int y, int width, int height, int *block_data) {
    int block_index = x + y * width;
    int left_block_data, top_block_data;
    
    // Potential out-of-bounds read
    if (x > 0) {
        left_block_data = block_data[block_index - 1];
    }
    
    // Potential out-of-bounds read
    if (y > 0) {
        top_block_data = block_data[block_index - width];
    }
    
    // ... decode current block using left and top block data
    
    // Potential out-of-bounds write
    block_data[block_index] = decode_current_block(left_block_data, top_block_data);
}

