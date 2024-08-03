static void update_quantization_parameters(MACROBLOCK *x, QUANT_PARAMS *params, int16_t delta_q[QUANT_PROFILES]) {
    MACROBLOCKD *const xd = &x->e_mbd;
    params->base_qindex = x->base_qindex;
    params->y_dc_delta_q = delta_q[Y_DC];
    params->uv_dc_delta_q = delta_q[UV_DC];
    params->uv_ac_delta_q = delta_q[UV_AC];

    // Vulnerable: potential buffer overflow if QUANT_PROFILES is larger than the size of params->delta_q
    memcpy(params->delta_q, delta_q, sizeof(delta_q[0]) * QUANT_PROFILES);
}
