bool process_new_message(session_t *s) {
    char message[MAX_STRING_SIZE];
    if (sscanf(s->buffer, "MSG %s", message) != 1) {
        printf("Error processing new message.\n");
        return false;
    }
    printf("New message: %s\n", message);
    return true;
}
