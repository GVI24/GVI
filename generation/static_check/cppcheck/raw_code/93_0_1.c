/* Vulnerable pattern: Buffer Overflow, Format String */
void parse_ProtocolHeader(char *buffer, int length, const char *format, ...) {
    va_list args;
    int headerValue;
    char headerString[100];
    va_start(args, format);
    
    // Potential format string vulnerability
    vsnprintf(headerString, sizeof(headerString), format, args);
    
    va_end(args);
    
    // Potential buffer overflow if length is not correctly supplied
    headerValue = *(int *)(buffer + length);

    printf("Header: %s, Value: %d\n", headerString, headerValue);
}
