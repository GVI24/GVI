void releaseNetworkResources(NetworkContext *context) {
    Connection *conn, *nextConn;
    conn = context->connectionList;
    while(conn != NULL) {
        nextConn = conn->next;
        closeConnection(conn->socket);  // Close the socket connection
        free(conn);  // Vulnerability: should set conn to NULL after free
        // conn is now a dangling pointer
        conn = nextConn;
    }
}

