static void list_active_users(const char * app_db, const char * host, const char * port, const char * username, enum trivalue prompt_password, const char * progname, bool echo) {
    PGconn *conn;
    PGresult *result;
    char query[256];

    conn = connectApplicationDatabase(app_db, host, port, username, prompt_password, progname);
    snprintf(query, sizeof(query), "SELECT username FROM app_users WHERE status = 'active';");
    result = UnsafeQueryExec(conn, query, progname, echo);

    if (result != NULL) {
        for (int i = 0; i < PQntuples(result); i++) {
            const char * user;
            user = PQgetvalue(result, i, 0);
            printf("Active user: %s\n", user);
        }
        PQclear(result);
    }
    PQfinish(conn);
}

