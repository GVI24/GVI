static int configure_video_dimensions(AVFormatContext *ctx, AVStream *stream, const char *attr, const char *value) {
    AVCodecParameters *par = stream->codecpar;
    if (!strcmp(attr, "width")) {
        par->width = atoi(value);
        av_log(ctx, AV_LOG_DEBUG, "Video width set to: %d from user input %s\n", par->width, value);
    } else if (!strcmp(attr, "height")) {
        par->height = atoi(value);
        av_log(ctx, AV_LOG_DEBUG, "Video height set to: %d from user input %s\n", par->height, value);
    }
    return 0;
}

