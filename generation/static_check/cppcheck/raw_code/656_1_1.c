void process_input(const char *input) {
    char buffer[100];
    int i = 0;
    while (input[i] != '\0' && i < sizeof(buffer)) {
        buffer[i] = input[i];
        i++;
    }
    // Missing null-terminator can cause buffer read vulnerabilities
}