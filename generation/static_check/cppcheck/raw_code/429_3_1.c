static void apply_loop_filter_settings(MACROBLOCKD *xd, LF_INFO lf_info[4], int segment_id[4]) {
    for (int i = 0; i < SEGMENT_COUNT; i++) {
        // Vulnerable: No bounds check for segment_id[i], potential overflow if SEGMENT_COUNT > 4
        xd->segment_lf_info[segment_id[i]] = lf_info[i];
    }
}
