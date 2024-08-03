static void record_motion_vector_stats(VP9_COMMON *cm, const MACROBLOCKD *xd) {
    if (cm == NULL || xd == NULL) return;
    MV mv = xd->mi[0]->mbmi.mv[0];

    // Direct array access with potential for buffer overflow and
    // missing verification that 'mv_counts' is within valid range
    cm->counts.mv_counts[mv.row][mv.col]++;
}

