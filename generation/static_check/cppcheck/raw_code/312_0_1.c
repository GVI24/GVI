#define MAX_USER_INPUT 256
#define MAX_QUERY_LEN 512

int execute_user_query(char *user_input) {
    char sql_query[MAX_QUERY_LEN];
    MYSQL *conn;

    // Initialize connection... (omitted for brevity)

    // Vulnerable to overflow if user_input is too large and to SQL injection
    snprintf(sql_query, sizeof(sql_query), "SELECT * FROM data WHERE input = '%s'", user_input);
    
    if (mysql_query(conn, sql_query)) {
        fprintf(stderr, "Query failed: %s\n", mysql_error(conn));
        return 1;
    }

    // Process query results... (omitted for brevity)

    return 0;
}