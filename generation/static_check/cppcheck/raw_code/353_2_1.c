static void custom_strcpy(char *dest, uint num, ...) {
    va_list args;
    va_start(args, num);
    
    while (num--) {
        char *src = va_arg(args, char *);
        while ((*dest++ = *src++)) { // If dest is not large enough, overflow occurs
            // copying strings
        }
        // No check to ensure dest has enough space
    }
    
    va_end(args);
}

