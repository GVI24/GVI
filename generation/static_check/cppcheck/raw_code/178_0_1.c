static void drop_database_user(const char *username, PGconn *conn) {
    char query[256];
    sprintf(query, "DROP USER %s;", username); // Unsafe
    if (PQexec(conn, query) == NULL) {
        fprintf(stderr, "Error dropping user: %s\n", PQerrorMessage(conn));
    }
}

