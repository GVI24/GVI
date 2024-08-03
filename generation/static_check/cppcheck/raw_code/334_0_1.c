static int initialize_video_stream(AVCodecContext *avctx, BitStream *bs) {
    int width, height;
    if (!read_stream_dimensions(bs, &width, &height)) {
        // Vulnerability: No error handling if reading stream dimensions fails.
        return -1;
    }
    avctx->width = width;
    avctx->height = height;
    
    // Vulnerability: No check if allocating the codec context fails.
    if (!allocate_codec_context(avctx, width, height)) {
        av_log(avctx, AV_LOG_ERROR, "Could not allocate codec context.\n");
        return -1;
    }
    return 0;
}

