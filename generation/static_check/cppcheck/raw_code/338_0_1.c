int calculate_bitrate(const ENCODER *encoder, int quality) {
    const int base_quality = encoder->base_quality;
    int bitrate = base_quality * quality * quality;
    if (encoder->config.pass == 2 && encoder->frame.type != I_FRAME) {
        bitrate = (bitrate * encoder->complexity_adjustment) / 100;
        if (bitrate < 0) {
            // Handle potential overflow case
        }
    }
    return bitrate;
}

