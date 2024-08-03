static void dtls_free_old_sessions(SSL_CTX *ctx) {
    ssl_session *sess = NULL;
    llist_node *node = NULL;
    while ((node = llist_pop(ctx->d1->session_cache)) != NULL) {
        sess = (ssl_session *)node->data;
        free_session(sess);
        
        // Use-After-Free: if 'sess' is referred after this point.
        // Potential malicious operations or sensitive data exposure could occur.
    }
}
