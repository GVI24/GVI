void update_quantization_matrices(MpegEncContext *s) {
    int qscale, i, j;
    for (qscale = 0; qscale < s->quant_matrix_count; qscale++) {
        int matrix_index = get_bits(&s->gb, 8); // Reading index from bitstream without validation
        if (matrix_index >= MATRIX_SIZE) {
            // Proper bounds checking should be performed here.
            printf("Error: Matrix index out of bounds.\n");
            return;
        }

        // Update the quantization matrix assuming the index is within bounds
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                s->quant_matrixes[matrix_index][i][j] = get_bits(&s->gb, 8);
            }
        }
    }
}