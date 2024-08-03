// Example 4: Vulnerable Function for Parsing Command-Line Switches
char *get_switch_value(char *args, const char *switch_name) {
    char *arg_start, *value_start;
    size_t switch_len = strlen(switch_name);
    arg_start = args;

    while (*arg_start) {
        if (strncmp(arg_start, switch_name, switch_len) == 0 && *(arg_start + switch_len) == '=') {
            arg_start += switch_len + 1; // Move past the switch and the '='
            value_start = arg_start;

            while (*arg_start && *arg_start != ' ') {
                if (*arg_start == '\\' && *(arg_start + 1)) {
                    char *temp = arg_start;
                    // Vulnerable part: No bounds checking
                    while (*temp) {
                        *temp = *(temp + 1); // Overwrites the current character with the next one
                        temp++;
                    }
                } else {
                    arg_start++;
                }
            }
            
            if (*arg_start) *arg_start = '\0'; // Null-terminate the value
            return value_start;
        }
        
        // Proceed to the next argument
        while (*arg_start && *arg_start != ' ') {
            arg_start++;
        }
        
        while (*arg_start == ' ') {
            arg_start++;
        }
    }

    return NULL; // Switch not found
}