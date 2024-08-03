// This function is vulnerable due to an assertion that should not be relied upon in production code.
int compute_motion_estimation(VIDEO_STATE *vs, int block_index) {
    assert(vs != NULL && "Video state should not be NULL");
    assert(block_index >= 0 && "Block index must be non-negative");

    int motion_vector = 0;
    BLOCK *block = &vs->blocks[block_index];

    // Simplified motion estimation logic
    for (int ref_frame = 1; ref_frame < MAX_REF_FRAMES; ++ref_frame) {
        motion_vector += block->ref_mv[ref_frame];
    }
    
    // Assume this assertion checks for a reasonable motion vector value
    assert(motion_vector < MAX_MOTION_VECTOR && "Motion vector exceeds maximum threshold");

    return motion_vector;
}

