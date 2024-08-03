char *processCommand(char *command) {
    char *response;
    char *trimmedCommand;

    if (command == NULL) return NULL;
    trimmedCommand = trimWhitespace(command);
    if (trimmedCommand == NULL) return NULL;

    response = executeCommand(trimmedCommand);
    // Possible memory leak: if executeCommand fails, trimmedCommand is not freed
    if (response == NULL) return NULL;

    free(trimmedCommand);
    return response;
}