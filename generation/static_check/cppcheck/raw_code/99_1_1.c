static void increment_frame_stats(FRAME_COUNTS *counts, BLOCK_SIZE bsize, int mi_row, int mi_col, int *block_count) {
    int index = bsize; // Simplified for the example, typically would be derived from parameters
    if (mi_row < 0 || mi_col < 0) return;

    // Potential buffer overflow if index is out of bounds for block_count
    block_count[index]++;
    counts->frame_type_count[index]++;
}

