static void list_table_entries(const char *table_name, const char *progname, bool echo) {
    PGconn *conn;
    PGresult *result;
    char query[256];

    conn = connectDatabase("mydb", NULL, NULL, "user", false, progname);
    // Vulnerable to SQL injection through table_name variable
    snprintf(query, sizeof(query), "SELECT * FROM %s;", table_name);

    if (echo) {
        printf("Listing entries for table: %s\n", table_name);
    }

    result = executeQuery(conn, query, progname, echo);
    PQclear(result);
    PQfinish(conn);
}

