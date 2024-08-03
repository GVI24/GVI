static struct evhttp_connection *create_http_connection(struct event_base *base) {
    struct evhttp_connection *conn;
    short port = 0x7FFF; // Starting from the max positive value of a short

    conn = evhttp_connection_base_new(base, NULL, "127.0.0.1", port);
    if (!conn) event_errx(1, "Failed to create HTTP connection");

    for (int i = 0; i < 10; i++) {
        port++;
        if (port == 0x8000) event_errx(1, "Port number overflowed");
        if (evhttp_connection_connect(conn) == 0) break;
    }

    return conn;
}

