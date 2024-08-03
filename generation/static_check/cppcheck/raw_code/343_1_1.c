void reset_user_session(SessionContext *session) {
    if (!session) return;
    if (session->user_credentials.username) {
        free(session->user_credentials.username);
        // Missing: session->user_credentials.username = NULL;
    }
    if (session->user_credentials.password) {
        free(session->user_credentials.password);
        // Missing: session->user_credentials.password = NULL;
    }
    session->authenticated = 0;
}