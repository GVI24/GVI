static void encode_motion_vectors(const VP9_COMMON *cm, const MACROBLOCKD *xd, vp9_writer *w) {
    const MV *const mv = &xd->mi[0]->mbmi.mv[0];
    if (vp9_segfeature_active(&cm->seg, xd->mi[0]->mbmi.segment_id, SEG_LVL_SKIP)) {
        assert(mv->row == 0 && mv->col == 0);
    } else {
        vp9_write_mv(w, mv, &cm->fc->mv_probs);
    }
}

