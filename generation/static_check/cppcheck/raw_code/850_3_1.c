void process_user_data(UserContext *user_ctx) {
    char data_buffer[256];
    int data_size;
    int ret = get_user_data_size(user_ctx->input_stream, &data_size);
    if (ret != 0 || data_size > 256) {
        av_log(user_ctx, AV_LOG_ERROR, "User data size error\n");
        return;
    }
    // If get_user_data_size can be influenced, or if there is an integer overflow, it can lead to buffer overflow
    read_user_data(user_ctx->input_stream, data_buffer, data_size);
    handle_user_request(data_buffer, user_ctx);
}