static void block_copy(uint8_t* src, int src_stride, uint8_t* dest, int dest_stride, int block_width, int block_height) {
    int i, j;
    for (j = 0; j < block_height; j++) {
        for (i = 0; i < block_width; i++) {
            dest[j * dest_stride + i] = src[j * src_stride + i]; // Potential buffer overflow
        }
    }
}