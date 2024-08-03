static void replicate_sbr_harmonic(SBRHarmonic *target, const SBRHarmonic *source) {
    target->bs_sinusoidal_presence = source->bs_sinusoidal_presence;
    memcpy(target->h_sbr_frequencies, source->h_sbr_frequencies, sizeof(source->h_sbr_frequencies));
    target->num_h_sbr = source->num_h_sbr;
    if (target->num_h_sbr > MAX_H_FREQ) {
        target->h_sbr_frequencies[MAX_H_FREQ] = target->h_sbr_frequencies[0];
    }
    target->sbr_harmonic_level = source->sbr_harmonic_level;
}