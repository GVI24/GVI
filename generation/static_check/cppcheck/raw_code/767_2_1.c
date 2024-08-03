void update_noise_levels(VP9_COMP *cpi) {
    VP9_COMMON *const cm = &cpi->common;
    vpx_clear_system_state();

    int noise_levels_size = cm->mi_rows * cm->mi_cols;
    // Vulnerable: No bounds checking for noise_levels before memset operation
    vpx_memset(cpi->noise_levels, 0, noise_levels_size * sizeof(cpi->noise_levels[0]));

    // Additional noise level adjustments might be made here
}

