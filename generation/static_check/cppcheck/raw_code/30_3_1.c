void zigzag_scan(int16_t *block, int16_t *zigzagged, int rows, int cols) {
    static const int zigzag_order[64] = { /* ZigZag order indexes */ };
    int16_t temp[64];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int zz_idx = zigzag_order[i * cols + j];
            temp[zz_idx] = block[i * cols + j]; // Potential overflow if rows or cols > 8
        }
    }
    for (int i = 0; i < rows * cols; ++i) {
        zigzagged[i] = temp[i];
    }
}