static void copy_motion_vectors(MACROBLOCK *x, MV_REFERENCE_FRAME mv_ref[REF_FRAMES], MOTION_VECTOR mv[REF_FRAMES]) {
    MACROBLOCKD *const xd = &x->e_mbd;
    for (int i = 0; i < REF_FRAMES; i++) {
        xd->last_frame_mvs[mv_ref[i]] = mv[i]; // Vulnerable: No bounds check for mv_ref[i]
    }
}
