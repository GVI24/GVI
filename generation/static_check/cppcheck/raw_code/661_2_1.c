bool handle_client_input(session_t *s) {
    char input[MAX_STRING_SIZE];
    if (sscanf(s->buffer, "%s", input) != 1) {
        printf("Error handling client input.\n");
        return false;
    }
    printf("Handling client input: %s\n", input);
    return true;
}
