void parse_command_arguments(int argc, char *argv[]) {
    char command[64];
    for (int i = 1; i < argc; ++i) {
        strcat(command, argv[i]);  // No bounds checking for the command buffer
        strcat(command, " ");      // Potential buffer overflow if argv is too long
    }
}

