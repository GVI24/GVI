static int process_user_input(UserInputContext *uic, const char *input_stream, int stream_size) {
    char buffer[256];
    if (stream_size > 256) {
        av_log(uic->log_ctx, AV_LOG_ERROR, "Input stream too large.\n");
        return -1;
    }
    // Unsafe copy: potential buffer overflow if stream_size is incorrect
    memcpy(buffer, input_stream, stream_size);
    if (parse_user_input(uic->parser, buffer) < 0) {
        av_log(uic->log_ctx, AV_LOG_ERROR, "Failed to parse user input.\n");
        return -1;
    }
    return 0;
}

