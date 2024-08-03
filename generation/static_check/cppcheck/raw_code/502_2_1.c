static void transfer_sbr_channel_data(SBRChannel *dst, const SBRChannel *src) {
    dst->ch_noise_floor = src->ch_noise_floor;
    memcpy(dst->envelope_data, src->envelope_data, sizeof(src->envelope_data));
    memcpy(dst->noise_floor_data, src->noise_floor_data, sizeof(src->noise_floor_data));
    dst->envelope_data_index = src->envelope_data_index % MAX_ENVELOPE_SIZE;
    if (src->envelope_data_index < MAX_ENVELOPE_SIZE) {
        dst->envelope_data[src->envelope_data_index] = src->envelope_data[0];
    }
    dst->sbr_grid_index = src->sbr_grid_index;
    dst->sbr_grid[dst->sbr_grid_index] = dst->sbr_grid[0];
}
