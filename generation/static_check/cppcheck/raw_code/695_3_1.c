static int ac_pred_coeff(MpegEncContext *s, int idx) {
    int *coeff_array, pred_coeff;
    int left_idx = idx - 1, top_idx = idx - s->mb_stride;

    coeff_array = s->ac_coeff + idx;

    // Potential out-of-bounds access for the top row and leftmost column
    int left_coeff = coeff_array[left_idx];
    int top_coeff = coeff_array[top_idx];

    // Vulnerability: No checks for the first row and column elements
    if (abs(left_coeff) > abs(top_coeff)) {
        pred_coeff = left_coeff;
    } else {
        pred_coeff = top_coeff;
    }

    return pred_coeff;
}