void perform_motion_estimation(MOTION_ESTIMATION_CTX *me_ctx, BLOCK *blocks, int num_blocks) {
    VECTOR mvectors[100];
    for (int i = 0; i < num_blocks; i++) {
        mvectors[i] = estimate_motion_vector(me_ctx, &blocks[i]); // Potential out-of-bounds write
    }
    // ... (rest of the code that utilizes motion vectors) ...
}

