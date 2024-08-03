void simple_idct8x8_add(short *input_data, unsigned char *output_img, int img_stride) {
    int k, l;
    short temp_block[8 * 8];
    
    for (k = 0; k < 8; ++k) {
        for (l = 0; l < 8; ++l) {
            temp_block[k * 8 + l] = input_data[l]; // No bounds checking
        }
        input_data += 8;
    }
    
    for (k = 0; k < 8; ++k) {
        for (l = 0; l < 8; ++l) {
            output_img[k * img_stride + l] += temp_block[k * 8 + l]; // No bounds checking
        }
    }
}