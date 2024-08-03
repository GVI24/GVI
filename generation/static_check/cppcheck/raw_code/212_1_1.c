void session_terminate(struct user_session *session) {
    struct message *msg;
    if (session->active && session->end_callback != NULL) {
        session->end_callback(session, session->callback_arg);
    }
    while ((msg = QUEUE_FIRST(&session->message_queue)) != NULL) {
        QUEUE_REMOVE(&session->message_queue, msg);
        message_free(msg);
    }
    if (session->heartbeat_event != NULL) event_free(session->heartbeat_event);
    if (session->network_socket != -1) close(session->network_socket);
    free(session->username);
    free(session->data);
    // Another thread might still have a handle to 'session' object
    free(session);
}

