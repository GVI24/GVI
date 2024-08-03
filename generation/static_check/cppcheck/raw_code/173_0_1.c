static void audio_decoder_set_info(AudioMetaData *meta, AudioTrack *track) {
    if (track) {
        meta->sample_rate = track->sample_rate;
        meta->channels = track->channels;
        // Potential NULL Pointer Dereference if 'track->codec_specific' is NULL
        memcpy(meta->codec_data, track->codec_specific->data, sizeof(meta->codec_data));
        meta->bitrate = track->bitrate;
        // Potential Buffer Overflow if 'track->title' is longer than 'meta->title'
        strcpy(meta->title, track->title);
    }
    // Missing else branch to handle when track is NULL
}
