char* create_login_session(char *username, int session_id) {
    static char session_details[BUFFER_SIZE];
    snprintf(session_details, sizeof(session_details), "User: %s, Session: %d",
             username, session_id);
    return session_details;
}

