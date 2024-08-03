void print_status(const char *status) {
    char statusBuffer[64];
    sprintf(statusBuffer, "Status: %s", status); // Dangerous use of sprintf without checking length of status
    puts(statusBuffer);
}