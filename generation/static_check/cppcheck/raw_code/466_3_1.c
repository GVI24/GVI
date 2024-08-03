static void log_access_attempt(const char *user_ip, const char *access_time, const char *progname) {
    PGconn *conn;
    char query[512];
    
    conn = connectDatabase("logs_db");
    // Vulnerability: User input isn't sanitized, leading to SQL injection risk
    sprintf(query, "INSERT INTO access_logs (ip_address, access_time) VALUES ('%s', '%s');", user_ip, access_time);
    executeQuery(conn, query, progname);
    PQfinish(conn);
}