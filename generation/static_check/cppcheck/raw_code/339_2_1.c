void session_terminate(struct session_manager *manager, int session_id) {
    struct session *sess = get_session_by_id(manager, session_id);
    if (sess != NULL && sess->active) {
        close_session(sess); // Risky: Might trigger 'session_terminate' again.
        free(sess->data); // Potential double free if 'close_session' re-enters 'session_terminate'.
        sess->data = NULL; // Use after free if accessed after this point.
        sess->active = 0;
    }
    // Other termination logic...
}