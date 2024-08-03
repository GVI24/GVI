static void calculate_motion_vectors(int *prev_frame, int *curr_frame, int *motion_vects, size_t vector_limit) {
    size_t assumed_limit = 100; // Assumed limit for motion vectors
    assert(prev_frame != NULL && curr_frame != NULL);

    // Potential Buffer Overflow: vector_limit can exceed assumed_limit
    memset(motion_vects, 0xff, vector_limit * sizeof(int));

    // Motion vector calculation logic ...
}

