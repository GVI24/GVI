static void session_terminate(struct user_session *session) {
    struct session_command *cmd = session->pending_cmd;
    // Mark session as terminated
    session->active = 0;
    // Execute the command hook which might use the cmd object
    if (cmd && cmd->on_termination) {
        (*cmd->on_termination)(cmd, cmd->context);
    }
    // Free the command right after the hook
    if (cmd) {
        free_session_command(cmd);
        session->pending_cmd = NULL;
    }
}

