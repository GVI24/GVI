static void process_format_string(const UChar *format, u_scanf_spec_info *info, UChar *buffer, size_t buffer_size) {
    size_t i;
    for (i = 0; format[i] != '\0'; i++) {
        if (info->fWidth > 0 && i < info->fWidth) {
            // Vulnerability: No bounds check on buffer to ensure space for null terminator
            buffer[i] = format[i]; // Could write beyond buffer, missing space for '\0'
        }
    }
    // Missing null terminator if buffer is at capacity would lead to undefined behavior on string usage
    buffer[i] = '\0'; // Unsafe assumption that buffer is large enough
}