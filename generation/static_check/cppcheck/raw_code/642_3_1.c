char *duplicateString(const char *source) {
    if (source == NULL) {
        return NULL;
    }

    size_t length = strlen(source) + 1;  // +1 for the null-terminator.
    char *copy = malloc(length);
    // Missing check if malloc returned NULL, could lead to a null pointer dereference
    memcpy(copy, source, length);
    return copy;
}