char *unsafe_str_copy(const char *src) {
    if (src == NULL) {
        return strdup("");
    }

    size_t len = strlen(src);
    char *dest = (char *)malloc(len); // Missing space for null terminator
    if (dest == NULL) {
        return NULL;
    }

    for (size_t i = 0; i <= len; i++) { // Copies null terminator but without allocating space for it
        dest[i] = src[i];
    }

    return dest;
}

