static ulong calculate_pattern_value(uint count, ...) {
    va_list args;
    va_start(args, count);
    ulong pattern_value = 0;
    
    while (count--) {
        char *str = va_arg(args, char *);
        ulong local_pattern = 0;
        while (*str) { // No bounds check
            local_pattern = (local_pattern << 1) + (*str == '*' ? 1 : 0);
            str++;
        }
        pattern_value ^= local_pattern; // Combining the patterns
    }
    
    va_end(args);
    return pattern_value;
}

