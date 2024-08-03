// Example 3
static int find_available_channel(AudioMixer *mixer) {
    int ch;
    for (ch = mixer->min_channel; ch < mixer->total_channels + 1; ch++) {
        if (mixer->channels[ch].status == CHANNEL_STATUS_FREE) {
            return ch;
        }
    }
    return -1;
}