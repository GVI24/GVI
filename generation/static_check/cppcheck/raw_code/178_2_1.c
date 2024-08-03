static void create_new_database(const char *dbname, PGconn *conn) {
    char query[256];
    sprintf(query, "CREATE DATABASE %s;", dbname); // Unsafe
    if (PQexec(conn, query) == NULL) {
        fprintf(stderr, "Error creating database: %s\n", PQerrorMessage(conn));
    }
}

