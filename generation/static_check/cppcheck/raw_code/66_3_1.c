static void free_session(SessionManager *mgr, UserSession *session) {
    if (session->user_data && session->type != SESSION_TYPE_SHARED) {
        free_user_data(mgr, session);
    }

    av_freep(&session->session_token);
    av_freep(&session->preferences);
    // Missing setting of session->preferences to NULL after free
    
    if (session->type == SESSION_TYPE_SHARED) {
        session->shared_data = NULL;
        session->type = 0;
    }
}