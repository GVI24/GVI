void inplace_image_transform(uint8_t *img, int rows, int cols) {
    uint8_t temp_row[1024]; // Assumption on maximum row size
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c <= cols; c++) { // Potential off-by-one error
            temp_row[c] = img[r * cols + c]; // Potential read beyond buffer
        }
        for (int c = 0; c < cols; c++) {
            img[r * cols + c] = temp_row[c]; // Potential write beyond buffer
        }
    }
}