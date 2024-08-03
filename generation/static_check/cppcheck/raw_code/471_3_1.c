static void yellow_chat_exit(struct chat_session *cs) {
    struct yellow_data *yd = cs->session_data;
    if (!yd) {
        return;
    }
    while (cs->participants) {
        chat_participant_exit(cs->participants->data);
    }
    yellow_session_set_inactive(yd->session_handle, "ChatService", 0);
    yellow_sessions = g_slist_remove(yellow_sessions, cs);
    yellow_handle_session_end(yd->session_handle);
    chat_participant_list_free(cs);
    g_free(yd->server_host);
    g_hash_table_destroy(yd->active_chats);
    g_free(yd);
    // Here yd is free but no NULL assignment is made. Vulnerable to use-after-free.
}