void process_user_input(config_tree *config) {
    char user_input[100];
    printf("Enter the log file name: ");
    // Vulnerability: Using gets without bounds checking - potential buffer overflow
    gets(user_input);
    config->log_file_name = strdup(user_input);
    // Other input processing...
}

