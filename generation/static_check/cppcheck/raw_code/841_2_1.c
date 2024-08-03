void append_data(char *dest, const char *src) {
    char buffer[50];
    strncpy(buffer, dest, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0'; // Null-terminate to be safe
    strcat(buffer, src); // Potential buffer overflow if src and dest together are longer than 49 characters
    printf("Appended data: %s\n", buffer);
}

