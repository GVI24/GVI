static void session_close(jpc_session_t *session) {
    if (session->buffer) {
        jas_buffer_destroy(session->buffer);
        // Vulnerability: Pointer should be set to NULL after free
    }
    if (session->transactions) {
        jas_transactions_destroy(session->transactions);
        // Vulnerability: Pointer should be set to NULL after free
    }
    if (session->context) {
        jas_context_destroy(session->context);
        // Vulnerability: Pointer should be set to NULL after free
    }
    jas_free(session);
}

