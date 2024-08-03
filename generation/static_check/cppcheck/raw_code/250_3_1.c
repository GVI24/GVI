static int calculate_quant_matrix(H264Context* h, int qp) {
    int mb_xy = h->mb_xy;
    int qm_idx = qp + mb_xy; // Potential for out-of-bounds index

    // Vulnerability: no bounds checking before accessing
    uint8_t* quant_matrix = h->quant_matrixes[qm_idx];

    // Potential out-of-bounds access and modification
    for (int i = 0; i < 64; i++) {
        quant_matrix[i] = default_quant_matrix[i] / (qp % 6);
    }

    // Additional vulnerable points without proper bounds checking
    int left_qm_idx = mb_xy - 1;
    int top_qm_idx = mb_xy - h->mb_stride;

    // No bounds checking for left and top quant matrixes
    uint8_t* left_quant_matrix = h->quant_matrixes[left_qm_idx];
    uint8_t* top_quant_matrix = h->quant_matrixes[top_qm_idx];

    left_quant_matrix[0] = 255 / (qp % 6);
    top_quant_matrix[0] = 255 / (qp % 6);

    return 0;
}