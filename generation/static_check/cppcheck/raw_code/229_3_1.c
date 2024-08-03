static void encode_inter_mode(VP9_COMMON *const cm, const MACROBLOCKD *const xd, vp9_writer *w) {
    const MODE_INFO *mi = xd->mi[0];
    const INTER_MODE md = mi->mbmi.mode;
    if (vp9_segfeature_active(&cm->seg, mi->mbmi.segment_id, SEG_LVL_MODE)) {
        assert(md == vp9_get_segdata(&cm->seg, mi->mbmi.segment_id, SEG_LVL_MODE));
    } else {
        const int ctx = get_mode_context(cm, xd);
        vp9_write(w, md != NEARESTMV, cm->fc->inter_mode_probs[ctx][0]);
        if (md != NEARESTMV) {
            vp9_write(w, md != NEARMV, cm->fc->inter_mode_probs[ctx][1]);
        }
    }
}