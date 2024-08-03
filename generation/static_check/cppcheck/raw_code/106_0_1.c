static void apply_motion_vectors(MOTION_VECTOR_CALC *mv_calc, MOTION_VECTOR *vecs, int count) {
    int i;
    for (i = 0; i < count; i++) {
        // Direct assignment without checking if 'i' is within the bounds of 'vecs'
        vecs[i] = mv_calc->motion_vectors[i];
    }
}

