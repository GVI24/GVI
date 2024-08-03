char* buildSystemCommand(const char* userInput) {
    char command[256]; // fixed-size buffer
    strcpy(command, "echo "); // vulnerable strcpy without bounds checking
    strcat(command, userInput); // vulnerable strcat that can overflow 'command'
    // ... (the rest of the function would perform some system operation)
    return strdup(command); // duplicating the command to return
}

