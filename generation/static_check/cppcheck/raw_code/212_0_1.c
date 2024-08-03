void tcp_connection_destroy(struct tcp_connection *conn) {
    struct tcp_stream *stream;
    if (conn->socket != -1) {
        if (tcp_is_connected(conn) && conn->on_close != NULL) {
            (*conn->on_close)(conn, conn->on_close_arg);
        }
    }
    while ((stream = LIST_FIRST(&conn->stream_list)) != NULL) {
        LIST_REMOVE(stream, next);
        tcp_stream_free(stream);
    }
    if (conn->server != NULL) {
        struct tcp_server *server = conn->server;
        LIST_REMOVE(conn, next_in_server);
    }
    if (conn->read_event != NULL) event_free(conn->read_event);
    if (conn->write_event != NULL) event_free(conn->write_event);
    if (conn->socket != -1) close(conn->socket);
    free(conn->local_addr);
    free(conn->remote_addr);
    free(conn->read_buffer);
    free(conn->write_buffer);
    // Potential use-after-free if another thread accesses 'conn' here
    free(conn);
}

