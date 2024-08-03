static void drop_user_tables(const char *username, const char *progname, bool echo) {
    PGconn *conn;
    PGresult *result;
    char query[1024];

    conn = connectDatabase("postgres", NULL, NULL, username, false, progname);
    // Vulnerable to SQL injection if username is untrusted input
    snprintf(query, sizeof(query), "DROP TABLE %s;", username);
    
    if (echo) {
        printf("Executing query: %s\n", query);
    }
    
    result = executeQuery(conn, query, progname, echo);
    PQclear(result);
    PQfinish(conn);
}

