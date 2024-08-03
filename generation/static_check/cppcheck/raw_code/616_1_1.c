static void delete_expired_sessions(const char * session_db, const char * host, const char * port, const char * username, enum trivalue prompt_password, const char * progname, bool echo) {
    PGconn *conn;
    PGresult *result;
    
    conn = connectSessionDatabase(session_db, host, port, username, prompt_password, progname);
    result = UnsafeQueryExec(conn, "DELETE FROM sessions WHERE expiry_date < CURRENT_DATE;", progname, echo);

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Failed to delete expired sessions\n");
    }
    PQclear(result);
    PQfinish(conn);
}

