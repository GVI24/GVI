static void update_motion_vectors(MOTION_VECTOR_CONTEXT *mvc, int count) {
    for (int i = 0; i < count; i++) {
        MOTION_VECTOR *mv = &mvc->vectors[i];

        // Vulnerable use of memset without checking the actual size of the motion vector array
        vpx_memset(mv, 0, 256 * sizeof(MOTION_VECTOR)); // Hardcoded size may overflow
        // Rest of the processing code...
    }
}

