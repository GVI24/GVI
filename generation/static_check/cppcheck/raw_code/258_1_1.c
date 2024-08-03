static int save_user_input(const char *input) {
    char user_data[256];
    int input_length = strlen(input);
    // Vulnerability: user input can cause overflow if larger than user_data buffer
    strcpy(user_data, input);
    // Further processing...
    return 0;
}

