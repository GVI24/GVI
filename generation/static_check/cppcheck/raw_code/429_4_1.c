static void record_reference_frames_usage(MACROBLOCKD *xd, int ref_frame_usage[4], int valid_refs[4]) {
    for (int i = 0; i < MAX_REF_FRAMES; i++) {
        // Vulnerable: Refers beyond array bounds if MAX_REF_FRAMES > 4
        xd->ref_frame_usage[i] = ref_frame_usage[i];
        xd->valid_ref_frames[i] = valid_refs[i];
    }
}