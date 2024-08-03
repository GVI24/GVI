connection_t *network_connection_init(char *address, int port) {
    connection_t *connection = malloc(sizeof(connection_t));

    if (!connection) {
        return NULL;
    }

    connection->internal_data = initiate_connection(address, port); // Memory allocated here
    if (!connection->internal_data) {
        free(connection); // Fails to nullify the pointer after free
        return NULL;
    }

    // Missing error handling for unsuccessful connection initialization

    return connection;
}

