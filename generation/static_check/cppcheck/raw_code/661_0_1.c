bool parse_session_init(session_t *s) {
    char session_data[MAX_STRING_SIZE];
    if (sscanf(s->buffer, "INIT %s %d", session_data, &s->session_id) != 2) {
        printf("Error parsing session initialization data.\n");
        return false;
    }
    s->username = strdup(session_data);
    return true;
}
