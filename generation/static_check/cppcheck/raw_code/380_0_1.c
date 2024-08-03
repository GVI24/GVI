// Vulnerability: Buffer Overflow via unchecked string copy
void log_message(char *message) {
    char log_buffer[256];
    strcpy(log_buffer, message); // Dangerous: No bounds checking
    printf("Log: %s\n", log_buffer);
}