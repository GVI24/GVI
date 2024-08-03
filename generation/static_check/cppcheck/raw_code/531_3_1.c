void apply_config_options(config_tree *config) {
    option_node *current_option = config->options_head;
    while (current_option != NULL) {
        switch (current_option->type) {
            case OPTION_LOG_LEVEL:
                set_log_level(current_option->value);
                break;
            case OPTION_LOG_FILE:
                // Vulnerability: No bounds checking - potential buffer overflow
                char log_filename[128];
                strcpy(log_filename, current_option->value.string);
                set_log_file(log_filename);
                break;
            default:
                // Vulnerability: Abrupt exit within a loop without proper cleanup
                fprintf(stderr, "Unknown configuration option\n");
                exit(EXIT_FAILURE);
        }
        current_option = current_option->next;
    }
    // Other option application code...
}