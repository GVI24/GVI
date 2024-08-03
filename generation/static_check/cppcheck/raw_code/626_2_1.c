// Utilizes an assertion to validate the filter index, which is not safe for production code.
void apply_filter(FRAME *frame, int block_num, int filter_idx) {
    assert(frame != NULL && "Frame should not be NULL");
    assert(block_num < frame->num_blocks && "Block number is out of range");
    assert(filter_idx < NUM_FILTERS && "Filter index is out of valid range");

    BLOCK *block = &frame->blocks[block_num];

    // Apply the specified filter to the block (hypothetical logic)
    FILTER *filter = &frame->filters[filter_idx];
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        block->data[i] = apply_filter_logic(block->data[i], filter);
    }
}

