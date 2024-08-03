static int process_audio_block(AudioBlock *block, BitStream *bs) {
    if (get_bits(bs, 1)) {
        skip_bits_long(bs, 12);
    }
    
    block->dual_channel = get_bits(bs, 1);
    if (block->dual_channel) {
        read_channel_data(block->channel1_data, bs);
        memcpy(block->channel2_data, block->channel1_data, 512); // Arbitrary number, potential for overflow.
    } else {
        read_channel_data(block->channel1_data, bs);
        read_channel_data(block->channel2_data, bs);
    }
    
    get_tonal_components(bs, block->tonal_components, block->tonal_count);    
    return 0;
}