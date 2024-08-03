int extract_header_values(unsigned char *header, int num_fields, const char *trace_fmt, ...) {
    char trace_buffer[1024];
    va_list argp;
    va_start(argp, trace_fmt);
    vsprintf(trace_buffer, trace_fmt, argp); // Format string vulnerability
    va_end(argp);

    int offset = 0;
    for (int i = 0; i < num_fields; i++) {
        if (offset >= 1024) {
            break; // Attempt to stop buffer overflow but it's too late
        }
        printf("Header %d: %02X\n", i, header[offset]);
        offset += 2; // Assumes header is in 2-byte records without checking
    }
    printf("Trace: %s\n", trace_buffer);
    return offset;
}