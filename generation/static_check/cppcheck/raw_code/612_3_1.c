void apply_filter_to_block(int block_index, int block_size, unsigned char *frame_data, int width, int height, int filter_strength) {
    int block_x = (block_index % (width / block_size)) * block_size;
    int block_y = (block_index / (width / block_size)) * block_size;
    for (int y = block_y; y < block_y + block_size; y++) {
        for (int x = block_x; x < block_x + block_size; x++) {
            int sum = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    // Vulnerability: Potential out-of-bounds read
                    int pixel = frame_data[(y + ky) * width + (x + kx)];
                    sum += pixel * filter_strength;
                }
            }
            // Vulnerability: Potential out-of-bounds write
            frame_data[y * width + x] = sum / 9;
        }
    }
}