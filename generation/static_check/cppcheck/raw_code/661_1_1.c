bool parse_user_command(session_t *s) {
    char command[MAX_STRING_SIZE];
    if (sscanf(s->buffer, "COMMAND %s", command) != 1) {
        printf("Error parsing user command.\n");
        return false;
    }
    printf("Received command: %s\n", command);
    return true;
}
