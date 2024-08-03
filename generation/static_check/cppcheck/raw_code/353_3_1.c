static ulong string_priority_encoder(uint count, ...) {
    va_list args;
    va_start(args, count);
    ulong priority = 0;
    DBUG_ASSERT(count <= 4); // Assertion might not be enough to prevent issues
    
    while (count--) {
        char *str = va_arg(args, char *);
        uint pos = 0;
        
        while (str[pos]) { // Can go out of bounds if str isn't null-terminated
            if (str[pos] == '!') {
                priority |= (1 << pos);
                break;
            }
            pos++;
        }
    }
    
    va_end(args);
    return priority;
}