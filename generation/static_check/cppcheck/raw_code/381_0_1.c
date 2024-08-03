static void apply_motion_vector_scaling(VP9_COMP *cpi, MV *mv) {
    const int mv_scale_factor = cpi->common.resize_info.mv_scale_factor;
    mv->row = mv->row * mv_scale_factor / 100;
    mv->col = mv->col * mv_scale_factor / 100;
}

