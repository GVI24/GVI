static void adjust_quantization(VideoEncoder *encoder, int quality, int *quant_matrix) {
    int base_quant = encoder->base_quant * quality; // potential overflow

    for (int i = 0; i < 64; i++) {
        int adjusted_quant = base_quant * encoder->quant_weight[i]; // potential overflow
        quant_matrix[i] = adjusted_quant >> 2;  // potential overflow if adjusted_quant is too large
    }
}

