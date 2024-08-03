void manipulate_string(char *input) {
    char *buffer = strdup(input);
    // ... manipulation logic...
    free(buffer);
    // Vulnerability: use after free - 'buffer' is used after it has been freed
    printf("%s\n", buffer);
}