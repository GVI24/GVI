static void update_account_status(const char *user_id, const char *status, const char *progname) {
    PGconn *conn;
    char query[256];
    
    conn = connectDatabase("accounts_db");
    // Vulnerable: Unsanitized input in SQL query
    sprintf(query, "UPDATE accounts SET status = '%s' WHERE id = '%s';", status, user_id);
    executeQuery(conn, query, progname);
    PQfinish(conn);
}

