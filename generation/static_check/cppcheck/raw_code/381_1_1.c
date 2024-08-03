static void set_reference_frame(VP9_COMP *cpi, uint8_t **ref_frame_buffer) {
    VP9_COMMON *const cm = &cpi->common;
    int ref_frame_index = cm->frame_refs[cm->new_fb_idx].idx;
    *ref_frame_buffer = cm->frame_bufs[ref_frame_index].data;
}

