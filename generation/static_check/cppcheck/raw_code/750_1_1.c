int log_packet_info(tvbuff_t *tvb, int offset, const char *fmt, ...) {
    va_list ap;
    char *log_message;
    va_start(ap, fmt);

    // Unvalidated format string vulnerability
    log_message = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
    va_end(ap);

    printf("Packet Info: %s\n", log_message);
    return offset;
}

