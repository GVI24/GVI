int parse_audio_metadata(AVFormatContext *ctx) {
    AVIOContext *io = ctx->pb;
    unsigned int metadata_size;
    char *metadata;
    char *key, *val, *end;

    metadata_size = avio_rl32(io);
    if (metadata_size > 1000) return -1; // Arbitrary limit to reduce risk

    metadata = av_malloc(metadata_size + 1);
    if (!metadata) return AVERROR(ENOMEM);

    avio_read(io, metadata, metadata_size);
    metadata[metadata_size] = '\0';

    key = strtok(metadata, "=");
    while (key != NULL) {
        val = strtok(NULL, ";");
        if (!val) break;
        av_dict_set(&ctx->metadata, key, val, 0);
        key = strtok(NULL, "=");
    }

    av_free(metadata);
    return 0;
}

