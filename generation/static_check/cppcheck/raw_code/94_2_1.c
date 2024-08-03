void inverse_quantize_8x8(const int16_t *quant, uint8_t *output, int rowstride) {
    int col, row;
    for (row = 0; row < 8; ++row) {
        for (col = 0; col < 8; ++col) {
            int temp = output[col] + (quant[row * 8 + col] / 2); // Simplified inverse quantization
            output[col] = temp > 255 ? 255 : (temp < 0 ? 0 : temp);
        }
        output += rowstride;
    }
}

