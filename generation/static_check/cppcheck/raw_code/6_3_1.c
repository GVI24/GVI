static int setup_audio_channels(AudioMixer *mixer, int channel_count) {
    int i;
    mixer->channels = (AudioChannel **)malloc(channel_count * sizeof(AudioChannel *));
    if (!mixer->channels) return 1;

    for (i = 0; i < channel_count; i++) {
        mixer->channels[i] = (AudioChannel *)malloc(sizeof(AudioChannel));
        if (!mixer->channels[i]) {
            // Missing deallocation of previously allocated channels before returning
            return 1;
        }
    }
    mixer->num_channels = channel_count;
    return 0;
}