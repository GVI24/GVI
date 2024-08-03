static int parse_spectral_data(SpectralContext *spec_ctx, SpectralData *spec_data, BitReader *bit_reader) {
    if (get_bit1(bit_reader)) {
        skip_bits(bit_reader, 32);
    }
    
    spec_data->is_coupled = get_bit1(bit_reader);
    if (spec_data->is_coupled) {
        if (read_spectral_line_data(spec_ctx, &spec_data->line_data[0], bit_reader)) {
            return -1;
        }
        // Note: Potential buffer overflow if line_data[0] is larger than line_data[1].
        memcpy(&spec_data->line_data[1], &spec_data->line_data[0], sizeof(spec_data->line_data[0]));
    } else {
        if (read_spectral_line_data(spec_ctx, &spec_data->line_data[0], bit_reader) ||
            read_spectral_line_data(spec_ctx, &spec_data->line_data[1], bit_reader)) {
            return -1;
        }
    }
    
    if (get_bit1(bit_reader)) {
        read_harmonic_vector(bit_reader, spec_data->harmonic_vector, spec_data->num_lines);
    }
    
    return 0;
}