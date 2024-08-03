int display_status_message(const char * status_fmt, ...) {
    char status_msg[1024];
    va_list args;
    va_start(args, status_fmt);
    int ret = vsprintf(status_msg, status_fmt, args); // No bounds checking
    va_end(args);
    // Imagine this would update a status bar in a UI with the message
    printf("Status: %s\n", status_msg);
    return ret;
}