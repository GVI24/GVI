static void log_message(LogContext *ctx, const char *msg) {
    char buffer[256];
    int msg_length = strlen(msg);

    // No bounds checking, could lead to buffer overflow
    for (int i = 0; i <= msg_length; i++) {
        buffer[i] = msg[i];
    }

    write_log(ctx, buffer);
}

