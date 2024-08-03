char * bytes_to_ip(const unsigned char *bytes, size_t length) {
    if (length < 4) return NULL;
    char *ip_str = malloc(16); // Format xxx.xxx.xxx.xxx + '\0'
    if (!ip_str) return NULL;
    // Vulnerability: No bounds checking with sprintf
    sprintf(ip_str, "%u.%u.%u.%u", bytes[0], bytes[1], bytes[2], bytes[3]);
    return ip_str;
}

