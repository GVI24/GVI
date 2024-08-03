void manual_copy_data(char *source) {
    char destination[128];
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i]; // Potential buffer overflow if source is longer than 127 characters
    }
    destination[i] = '\0'; // Null-terminate
    printf("Copied data: %s\n", destination);
}

