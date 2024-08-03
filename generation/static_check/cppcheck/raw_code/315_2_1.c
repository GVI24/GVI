static int parse_codec_bitrate(AVFormatContext *ctx, AVStream *stream, const char *attr, const char *value) {
    AVCodecParameters *par = stream->codecpar;
    if (!strcmp(attr, "bitrate")) {
        par->bit_rate = atoi(value);
        if (par->bit_rate <= 0)
            av_log(ctx, AV_LOG_ERROR, "Invalid bitrate value: %s, must be positive integer\n", value);
    }
    return 0;
}

