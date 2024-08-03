#define BUFFER_SIZE 256

int parse_formatted_input(const char *format, ...) {
    char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, BUFFER_SIZE, format, args); // Potential overflow if input exceeds BUFFER_SIZE
    va_end(args);
    printf("%s\n", buffer);
    return strlen(buffer);
}