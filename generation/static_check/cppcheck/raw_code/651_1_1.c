void copy_data(char *source) {
    unsigned int len = strlen(source);
    if (len > 1024) return; // Assume max size is 1024

    char *dest = (char *)malloc(len); // Missing space for null terminator, len could overflow
    if (dest == NULL) return;

    memcpy(dest, source, len); // Buffer overflow if source is not null-terminated
    dest[len] = '\0'; // Potential out-of-bounds write
    printf("Copied data: %s\n", dest);
    free(dest);
}

