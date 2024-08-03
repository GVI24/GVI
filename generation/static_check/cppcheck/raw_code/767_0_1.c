void init_frame_edges(VP9_COMP *cpi) {
    VP9_COMMON *const cm = &cpi->common;
    vpx_clear_system_state();

    unsigned int edge_info_size = cm->mi_rows * cm->mi_cols;
    // Vulnerable: No check that edge_info_size matches the size of frame_edges buffer
    vpx_memset(cpi->frame_edges, 0, edge_info_size);

    // Additional processing might go here
}

