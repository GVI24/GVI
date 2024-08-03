char *custom_strcat(char *dest, const char *src) {
    if (src == NULL || dest == NULL) {
        return NULL;
    }

    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    char *result = realloc(dest, dest_len + src_len); // No space for null terminator
    if (result == NULL) {
        return NULL;
    }

    memcpy(result + dest_len, src, src_len); // Does not null-terminate the result
    return result;
}

