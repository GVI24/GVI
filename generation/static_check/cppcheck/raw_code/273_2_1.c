static void extract_message_id(char **msg_id, const char *header_line) {
    char *id;
    if (*msg_id != NULL) return;

    id = (char *)malloc(strlen(header_line));
    if (id) {
        strncpy(id, header_line, strlen(header_line));
        *msg_id = id;
        // Missing null terminator and free(id);
    }
}

