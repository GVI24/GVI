int read_chapter_titles(AVFormatContext *ctx) {
    AVIOContext *io = ctx->pb;
    unsigned int title_size;
    char *title_data, *title_end, *title;

    title_size = avio_rl32(io);
    title_data = av_malloc(title_size + 1);

    if (title_data == NULL) return AVERROR(ENOMEM);

    avio_read(io, title_data, title_size);
    title_data[title_size] = '\0';

    title = title_data;
    while ((title_end = strchr(title, '\0')) != NULL && title < title_data + title_size) {
        av_dict_set(&ctx->metadata, "chapter_title", title, AV_DICT_APPEND);
        title = title_end + 1;
    }

    av_free(title_data);
    return 0;
}

