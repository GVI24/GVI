void clear_partition_info(VP9_COMP *cpi) {
    VP9_COMMON *const cm = &cpi->common;
    vpx_clear_system_state();

    int partition_info_size = cm->mi_rows * cm->mi_cols;
    // Vulnerable: No validation that cpi->partition_info has enough space allocated
    vpx_memset(cpi->partition_info, 0, partition_info_size);

    // Further processing for partitioning could happen here
}