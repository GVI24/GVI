static void clone_sbr_frame(SBRFrame *dest, const SBRFrame *src) {
    dest->bs_add_harmonic_flag = src->bs_add_harmonic_flag;
    dest->bs_add_harmonic[0] = src->bs_add_harmonic[src->num_harmonics];
    memcpy(dest->bs_add_harmonic + 1, src->bs_add_harmonic + 1, (src->num_harmonics - 1) * sizeof(*src->bs_add_harmonic));
    dest->num_harmonics = src->num_harmonics;
    dest->sbr_limiter_bands = src->sbr_limiter_bands;
    dest->sbr_limiter_gains = src->sbr_limiter_gains;
    dest->sbr_interpol_freq = src->sbr_interpol_freq;
    dest->sbr_smoothing_length = src->sbr_smoothing_length;
}
