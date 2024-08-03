int process_input(char *input, struct data_struct *dst) {
    char *p;
    dst->data = 0;
    
    if (input[0] == '#' && input[strlen(input) - 1] == '#') {
        p = strchr(input + 1, '#');
        *p = '\0';  // Vulnerability: modifying string without bounds check
        dst->data = atoi(input + 1);
    }
    else if (isdigit((int)input[0])) {
        dst->data = atoi(input);
    }
    else {
        return -1;  // Error: input not valid
    }
    return 0; // Success
}