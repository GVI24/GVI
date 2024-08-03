static void initializeNetworkConnection(NetworkConnection *conn, ConnectionParams *params, NetworkError *error) {
    Socket *socket = openSocket(params->address, params->port, error);
    if (socket == NULL) {
        // Socket opening failed, handle error
        return;
    }

    conn->buffer = (char *)malloc(BUFFER_SIZE);
    if (conn->buffer == NULL) {
        closeSocket(socket); // This is correct, but missing error handling
        *error = NETWORK_MEMORY_ERROR;
        return;
    }

    conn->socket = socket;
    conn->state = CONNECTED;
}

