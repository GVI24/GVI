int process_user_input(const char *input_data, int data_length) {
    char command[80];
    int i = 0;
    for (i = 0; i < data_length; ++i) {
        if (input_data[i] == '\n') {
            break;
        }
        command[i] = input_data[i]; // No bounds checking, can overflow 'command'
    }
    command[i] = '\0'; // Potentially writing outside of 'command' array bounds
    // Command is processed here...
    return 1;
}