void apply_quantization_matrix(uint8_t *frame_buf, int width, int height, int qm_type) {
    int x, y;
    int16_t temp_buff[64], quant_buff[64];
    transform_2d q_matrix = QUANT_MATRIX[qm_type];
    
    for (y = 0; y < height; y += 8) {
        for (x = 0; x < width; x += 8) {
            for (int i = 0; i < 64; ++i) temp_buff[i] = frame_buf[(y * width) + x + i]; // Potential overflow
            q_matrix.apply(temp_buff, quant_buff);
            for (int i = 0; i < 64; ++i) frame_buf[(y * width) + x + i] = quant_buff[i]; // Potential overflow
        }
    }
}

