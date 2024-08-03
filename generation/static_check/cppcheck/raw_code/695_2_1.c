static int intra_block_predict(MpegEncContext *s, int block_num) {
    int *block_data, predicted_val;
    int top_block_idx = block_num - s->mb_width;

    // Potential out-of-bounds if block_num is in the first row
    block_data = s->intra_block_values + block_num;

    // Vulnerability: No boundaries checking
    predicted_val = block_data[top_block_idx];

    return predicted_val;
}

