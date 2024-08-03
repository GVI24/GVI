static void alter_user_role(const char *username, const char *new_role, const char *progname, bool echo) {
    PGconn *conn;
    PGresult *result;
    char query[512];

    conn = connectDatabase("postgres", NULL, NULL, "admin", false, progname);
    // Potential SQL injection if inputs are from untrusted sources
    snprintf(query, sizeof(query), "ALTER ROLE %s SET role='%s';", username, new_role);

    if (echo) {
        printf("Altering role for user: %s\n", username);
    }

    result = executeQuery(conn, query, progname, echo);
    PQclear(result);
    PQfinish(conn);
}