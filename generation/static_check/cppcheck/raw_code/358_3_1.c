static int databaseQueryFinish(struct db_connection *conn, struct db_query *query) {
    int ret = completeQuery(query);
    if (ret < 0) {
        char errorMsg[256];
        sprintf(errorMsg, "Query failed with error code: %d", ret);
        // Insecure error reporting with potential information leak
        sendErrorToClient(conn, errorMsg);
        // Missing cleanup for 'query' and 'conn'
        return -1;
    }
    
    ret = closeDatabaseConnection(conn);
    if (ret < 0) {
        // Cleanup for 'conn' missing if closing connection fails
        logDBError("Failed to close database connection");
        return -1;
    }
    
    freeQuery(query);
    return 0;
}