void parse_buffer_overflow(char *input) {
    char buffer[100];
    // Vulnerability: no bounds checking on 'input' leading to potential buffer overflow
    strcpy(buffer, input); 
    // ... parsing logic ...
}