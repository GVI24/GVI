void reset_mv_predictions(VP9_COMP *cpi) {
    VP9_COMMON *const cm = &cpi->common;
    vpx_clear_system_state();

    int mv_pred_size = cm->mi_rows * cm->mi_cols * sizeof(*cpi->mv_pred);
    // Vulnerable: Improper use of sizeof on pointer type within vpx_memset
    vpx_memset(cpi->mv_pred, 0, mv_pred_size);

    // Additional processing for motion vector predictions
}

