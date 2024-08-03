static void reset_user_password(const char *username, const char *new_password, PGconn *conn) {
    char query[256];
    sprintf(query, "ALTER USER %s WITH PASSWORD '%s';", username, new_password); // Unsafe
    if (PQexec(conn, query) == NULL) {
        fprintf(stderr, "Error resetting password: %s\n", PQerrorMessage(conn));
    }
}

