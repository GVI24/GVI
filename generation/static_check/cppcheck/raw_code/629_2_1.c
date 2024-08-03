void update_ref_frame(MotionEstContext *mec, int pos_x, int pos_y, int vect_x, int vect_y) {
    int index = (pos_y * mec->stride + pos_x) * 2;

    // Unsafe updates to reference frame vectors without bound checks
    mec->ref_frame[index] = vect_x;
    mec->ref_frame[index + 1] = vect_y;

    for (int i = 0; i < 4; i++) { // Assume block size of 4
        for (int j = 0; j < 4; j++) {
            // Update reference frame with the new motion vector
            // This can write out of bounds of the ref_frame array
            mec->ref_frame[index + i * mec->stride * 2 + j * 2] = vect_x;
            mec->ref_frame[index + i * mec->stride * 2 + j * 2 + 1] = vect_y;
        }
    }
}

