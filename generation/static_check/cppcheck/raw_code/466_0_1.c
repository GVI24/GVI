static void delete_user_by_name(const char *username, const char *progname) {
    PGconn *conn;
    char query[256];
    
    conn = connectDatabase("users_db");
    snprintf(query, sizeof(query), "DELETE FROM users WHERE username = '%s';", username); // Vulnerable to SQL injection
    executeQuery(conn, query, progname);
    PQfinish(conn);
}

