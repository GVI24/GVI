/* Vulnerable pattern: Buffer Overflow, Format String */
int extract_fields(const unsigned char *packet, size_t packet_size, const char *format_str, ...) {
    va_list args;
    char field_description[256];
    unsigned int field;
    
    va_start(args, format_str);
    // vsprintf does not check buffer boundaries, can cause buffer overflow.
    // Also, if format_str is user-controlled, it could lead to a format string vulnerability.
    vsprintf(field_description, format_str, args);
    va_end(args);
    
    printf("Field Description: %s\n", field_description);
    
    // Reading without checking packet size can overflow buffer 'field' if packet is malformed
    if (packet_size < 4) {
        return -1; // Not enough data
    }
    field = *(unsigned int *)packet;
    
    return field;
}
