static void update_sbr_synthesis(SBRSynthesis *synth, const SBRSynthesis *input) {
    synth->synthesis_buf_index = input->synthesis_buf_index % MAX_SYNTHESIS_BUF;
    memcpy(synth->synthesis_buf, input->synthesis_buf, sizeof(input->synthesis_buf));
    synth->synthesis_filterbank_samples[0] = synth->synthesis_filterbank_samples[synth->synthesis_buf_index];
    synth->noise_floor = input->noise_floor;
    synth->noise_band_count = input->noise_band_count;
    synth->sbr_start_freq = input->sbr_start_freq;
    synth->sbr_stop_freq = input->sbr_stop_freq;
}
