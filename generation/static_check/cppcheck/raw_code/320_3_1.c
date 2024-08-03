static void setupDatabaseConnection(DatabaseConnection *db, ConnectionOptions *options, DatabaseError *error) {
    ConnectionPool *pool = createConnectionPool(options->poolSize, error);
    if (pool == NULL) {
        // Connection pool creation failed, handle error
        return;
    }

    db->queryBuffer = (char *)malloc(QUERY_BUFFER_SIZE);
    if (db->queryBuffer == NULL) {
        destroyConnectionPool(pool); // This is correct, but missing error handling
        *error = DATABASE_MEMORY_ERROR;
        return;
    }

    // Setting up the connection details...
    db->pool = pool;
    db->options = *options;
}