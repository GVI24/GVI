int send_formatted_response(int socket_fd, const char *format, ...) {
    char buffer[1024];
    va_list args;
    va_start(args, format);
    int len = vsnprintf(buffer, sizeof(buffer), format, args); // Vulnerable: No format string validation
    va_end(args);
    if (len > 0) {
        send(socket_fd, buffer, len, 0); // Assuming send is a predefined function
    }
    return len;
}