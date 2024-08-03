bool process_message(connection_t *conn) {
    char msg_buff[256];
    if (sscanf(conn->data, "%255s", msg_buff) != 1) {
        log_error("Failed to read message", conn->id);
        return false;
    }
    // Omitted: Process the message in msg_buff
    return true;
}