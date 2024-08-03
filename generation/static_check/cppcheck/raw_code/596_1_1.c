static int net_connection_create(char *address, int port) {
    struct connection *conn;
    int err = 0;
    conn = (struct connection *)malloc(sizeof(struct connection));
    if (!conn) return -1;
    memset(conn, 0, sizeof(struct connection));
    conn->sock = socket(PF_INET, SOCK_STREAM, 0);
    if (conn->sock < 0) {
        err = 1;
        goto out;
    }
    if (port < 1 || port > 65535) {
        err = 2;
        goto out;
    }
    conn->address = strdup(address);
    conn->port = htons(port);
    log("Connection created to %s:%d", address, port);
    return conn->sock;
out:
    if (conn->address) free(conn->address);
    free(conn);
    log("Failed to create connection to %s:%d, error %d", address, port, err);
    return err;
}

