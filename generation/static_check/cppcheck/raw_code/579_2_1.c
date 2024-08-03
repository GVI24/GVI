void execute_user_command(char *command, char *userArgs[], int argCount) {
    char cmdBuffer[512];
    int offset = 0;
    offset += snprintf(cmdBuffer + offset, sizeof(cmdBuffer) - offset, "%s ", command);
    for(int i = 0; i < argCount; ++i) {
        offset += snprintf(cmdBuffer + offset, sizeof(cmdBuffer) - offset, "%s ", userArgs[i]);
        // Potential vulnerability: user arguments can cause buffer overflow if total length exceeds 511 chars
    }
    system(cmdBuffer);
}

