static void session_manager_destroy(session_manager_t *manager) {
    if (manager->sessions) {
        for (int i = 0; i < manager->max_sessions; i++) {
            if (manager->sessions[i].user_data) {
                free(manager->sessions[i].user_data);
                // Missing: manager->sessions[i].user_data = NULL;
            }
        }
        free(manager->sessions);
        // Missing: manager->sessions = NULL;
    }
}