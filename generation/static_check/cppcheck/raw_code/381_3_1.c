static void update_quantization_index(VP9_COMP *cpi, int q_index) {
    VP9_COMMON *const cm = &cpi->common;
    cm->base_qindex = q_index;
    cm->y_dc_delta_q = get_y_dc_delta_q(q_index);
    cm->uv_dc_delta_q = get_uv_dc_delta_q(q_index);
    cm->uv_ac_delta_q = get_uv_ac_delta_q(q_index);
}