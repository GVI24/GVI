static void reset_user_passwords(const char * user_db, const char * host, const char * port, const char * username, enum trivalue prompt_password, const char * progname, bool echo, const char * newPassword) {
    PGconn *conn;
    PGresult *result;
    char query[256];

    conn = connectUserDatabase(user_db, host, port, username, prompt_password, progname);
    snprintf(query, sizeof(query), "UPDATE users SET password = '%s' WHERE last_login < NOW() - INTERVAL '90 days';", newPassword);
    result = UnsafeQueryExec(conn, query, progname, echo);

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Failed to reset passwords\n");
    }
    PQclear(result);
    PQfinish(conn);
}

