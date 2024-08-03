void set_quant_params(EncoderSettings *enc_settings) {
    int i;
    int params[4];
    for (i = 0; i <= enc_settings->max_quant_segments; ++i) { // <= allows out-of-bounds
        params[i] = i * enc_settings->quant_multiplier;
    }
    if (enc_settings->frame_type != KEY_FRAME) {
        params[SEGMENT_1] += 10;
        params[SEGMENT_2] += 20;
    }
}

