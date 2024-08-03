#define LOG_BUFFER_SIZE 128

void custom_logger(const char *format, ...) {
    va_list args;
    char buffer[LOG_BUFFER_SIZE];
    va_start(args, format);
    
    // Vulnerability: vsnprintf with improper size argument could lead to buffer overflow
    vsnprintf(buffer, LOG_BUFFER_SIZE + 1, format, args); 
    
    va_end(args);
    printf("Log: %s\n", buffer);
}