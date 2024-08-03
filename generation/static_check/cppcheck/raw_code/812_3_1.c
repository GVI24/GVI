void execute_query(char *user_input) {
    char query[1024];
    MYSQL *conn;  // Assume connection has been established

    snprintf(query, sizeof(query), "INSERT INTO table (column) VALUES ('%s')", user_input);  // Potential SQL injection
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
    }
}