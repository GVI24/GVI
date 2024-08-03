static void add_column_to_table(const char *tablename, const char *columnname, const char *columntype, PGconn *conn) {
    char query[512];
    sprintf(query, "ALTER TABLE %s ADD COLUMN %s %s;", tablename, columnname, columntype); // Unsafe
    if (PQexec(conn, query) == NULL) {
        fprintf(stderr, "Error adding column: %s\n", PQerrorMessage(conn));
    }
}