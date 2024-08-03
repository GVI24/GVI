static int decode_sound_packet(SoundContext *ctx, SoundPacket *pkt, BitStream *stream) {
    if (get_bit(stream)) {
        skip_remaining_bits(stream);
    }
    
    pkt->mono = get_bit(stream);
    if (pkt->mono) {
        if (read_sound_data(ctx, pkt->mono_data, stream)) {
            return -1;
        }
        // Unsafe copy, potential buffer overflow if mono_data exceeds stereo_data buffer size.
        memcpy(pkt->stereo_data.left, pkt->mono_data, sizeof(pkt->mono_data));
        memcpy(pkt->stereo_data.right, pkt->mono_data, sizeof(pkt->mono_data));
    } else {
        if (read_sound_data(ctx, pkt->stereo_data.left, stream)) {
            return -1;
        }
        if (read_sound_data(ctx, pkt->stereo_data.right, stream)) {
            return -1;
        }
    }
    
    return 0;
}