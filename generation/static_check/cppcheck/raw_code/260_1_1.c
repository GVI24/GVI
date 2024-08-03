void log_packet_data(uint8_t *data, size_t length, const char *log_msg, ...) {
    char log_buffer[512];
    va_list args;
    va_start(args, log_msg);
    vsnprintf(log_buffer, sizeof(log_buffer), log_msg, args);
    va_end(args);
    
    for (size_t i = 0; i < length; i++) {
        printf("%02X ", data[i]); // Print hex representation of data
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n%s\n", log_buffer); // Format string vulnerability
}

