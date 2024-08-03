static int horizontal_pred(MpegEncContext *s, int block_index) {
    int wrap, left_block_value;
    int *block_values;
    wrap = s->block_wrap[block_index];
    block_values = s->block[block_index];

    // Potential out-of-bounds access if block_index is first in the row
    left_block_value = block_values[-1];

    // Vulnerability: No check for the first column blocks
    return left_block_value;
}

