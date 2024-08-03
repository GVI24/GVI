static void clearSession(Session *session) {
    if (session != NULL && session->attributes != NULL) {
        for (int i = 0; i < session->numAttributes; i++) {
            if (session->attributes[i] != NULL) {
                free(session->attributes[i]->data);
                // Missing: session->attributes[i]->data = NULL;
                free(session->attributes[i]);
                // Missing: session->attributes[i] = NULL;
            }
        }
        free(session->attributes);
        // Missing: session->attributes = NULL;
    }
    free(session);
    // Missing: session = NULL;
}