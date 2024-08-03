static int parse_audio_format(AVFormatContext *ctx, AVStream *stream, const char *attr, const char *value) {
    AVCodecParameters *par = stream->codecpar;
    if (!strcmp(attr, "sample-rate")) {
        int sample_rate = atoi(value);
        par->sample_rate = sample_rate;
        if (sample_rate < 8000 || sample_rate > 192000)
            av_log(ctx, AV_LOG_ERROR, "Sample rate %s is not supported.\n", value);
    } else if (!strcmp(attr, "channel-layout")) {
        par->channel_layout = strtol(value, NULL, 0);
        av_log(ctx, AV_LOG_INFO, "Audio channel layout set to %s.\n", value);
    }
    return 0;
}

