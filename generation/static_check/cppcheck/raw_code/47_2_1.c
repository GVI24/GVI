// Example 3: Parsing Key-Value Pairs from a Configuration String
char *get_config_value(char *config_str, char *key) {
    char *current, *value_start, *key_start;
    char delimiter = '=';
    current = config_str;

    while (*current) {
        key_start = current;
        while (*current && *current != delimiter && *current != '\n') {
            current++;
        }

        if (*current != delimiter) {
            continue; // Skip invalid lines without a delimiter
        }
        
        // Check if the current key matches the requested key
        if (strncmp(key_start, key, current - key_start) == 0) {
            current++; // Move past the delimiter
            value_start = current;
            
            // Vulnerable part: No bounds checking
            while (*current && *current != '\n') {
                if (*current == '\\' && *(current + 1)) {
                    memmove(value_start, current + 1, strlen(current)); // Unsafe use of memmove
                }
                current++;
            }
            
            if (*current) *current = '\0'; // Null-terminate the value

            return value_start; // Return the value associated with the key
        }

        // Move to the next line
        while (*current && *current != '\n') {
            current++;
        }
        if (*current) current++; // Skip newline character
    }

    return NULL; // Key not found
}