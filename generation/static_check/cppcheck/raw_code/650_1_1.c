void custom_strcpy(char *dst, const char *src, int dst_size) {
    const char *end_marker = src;
    while (*end_marker != '#') end_marker++; // Find the custom end marker

    if (end_marker - src >= dst_size) return; // Vulnerable: Should be '>'

    while (src < end_marker) {
        *dst++ = *src++;  // Buffer overflow if dst_size is insufficient
    }
    *dst = '\0'; // Null-terminate the destination
}

