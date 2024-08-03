static int parse_gop_size(AVFormatContext *ctx, AVStream *stream, const char *attr, const char *value) {
    AVCodecParameters *par = stream->codecpar;
    if (!strcmp(attr, "gop-size")) {
        par->gop_size = atoi(value);
        if (par->gop_size < 0)
            av_log(ctx, AV_LOG_ERROR, "Invalid GOP size: %d, parsed from %s\n", par->gop_size, value);
    }
    return 0;
}