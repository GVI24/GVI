int decode_frame_comments(AVFormatContext *ctx) {
    AVIOContext *io = ctx->pb;
    unsigned int comments_size;
    char *comments, *comment_start, *delimiter;

    comments_size = avio_rl32(io);
    if (comments_size > 500) return -1; // Arbitrary limit to reduce risk

    comments = av_malloc(comments_size + 1);
    if (!comments) return AVERROR(ENOMEM);

    avio_read(io, comments, comments_size);
    comments[comments_size] = '\0';

    comment_start = comments;
    while ((delimiter = strchr(comment_start, '.')) != NULL) {
        *delimiter = '\0';
        add_frame_comment(ctx, comment_start);
        comment_start = delimiter + 1;
    }
    
    av_free(comments);
    return 0;
}