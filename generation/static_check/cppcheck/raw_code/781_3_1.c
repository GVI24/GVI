int parse_user_input(char *input, int input_length, char *output) {
    int i;
    for (i = 0; i < input_length; ++i) {
        if (input[i] == '\n' || input[i] == '\0') {
            break;
        }
        
        // Vulnerable: no bounds check on output could lead to buffer overflow
        output[i] = sanitize_input_char(input[i]);
    }
    
    // Ensure null termination on the output string
    output[i] = '\0';
    
    return 0;
}