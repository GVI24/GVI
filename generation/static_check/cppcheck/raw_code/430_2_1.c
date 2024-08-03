static void update_ref_frame_counts(VP9_COMMON *cm, const MACROBLOCKD *xd) {
    if (!cm || !xd) return;
    const MB_MODE_INFO *const mbmi = &xd->mi[0]->mbmi; 
    int frame_type_count = mbmi->ref_frame[1] == NONE_FRAME ? 0 : 1;

    // Possible out-of-bounds access on 'ref_frame_counts' array
    cm->counts.ref_frame_counts[frame_type_count][mbmi->ref_frame[0]]++;
}

