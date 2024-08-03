static uint get_length(uint count, ...) {
    va_list args;
    va_start(args, count);
    uint length = 0;
    
    while (count--) {
        char *str = va_arg(args, char *);
        while (*str++) { // Potentially iterate past buffer if not null-terminated
            length++;
        }
    }
    
    va_end(args);
    return length;
}

