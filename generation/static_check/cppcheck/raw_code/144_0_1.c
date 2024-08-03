static void custom_strncpy(UChar *dst, const UChar *src, size_t dst_size, u_scanf_spec_info *info) {
    size_t i;
    for (i = 0; i < info->fWidth && src[i] != '\0'; i++) {
        if (i < dst_size) {
            dst[i] = src[i];
        } else {
            // Vulnerability: Exceeds the destination buffer size.
            dst[i] = src[i]; // Unsafe access beyond buffer
        }
    }
    if (i < dst_size) {
        dst[i] = '\0';
    }
}

