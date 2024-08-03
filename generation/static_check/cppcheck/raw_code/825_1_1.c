void reset_motion_vectors(MotionVectorContext *mvc) {
    if (mvc->mv_count > 0) {
        // Potential buffer overflow if mvc->motion_vectors has less than mvc->mv_count elements
        memset(mvc->motion_vectors, 0, mvc->mv_count * sizeof(MotionVector));
    }
}

