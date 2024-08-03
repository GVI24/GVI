int load_subtitle_data(AVFormatContext *ctx) {
    AVIOContext *io = ctx->pb;
    unsigned int sub_size, index;
    char *subtitles;
    char *line, *next_line;

    sub_size = avio_rl32(io);
    subtitles = av_malloc(sub_size);

    if (subtitles == NULL) return AVERROR(ENOMEM);

    avio_read(io, subtitles, sub_size);

    line = subtitles;
    while ((next_line = strchr(line, '\n')) != NULL) {
        *next_line = '\0';
        process_subtitle_line(ctx, line);
        line = next_line + 1;
    }

    av_free(subtitles);
    return 0;
}

