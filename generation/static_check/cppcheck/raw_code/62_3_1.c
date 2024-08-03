#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handle_http_query(char *query) {
    char sql_query[1024];

    // Vulnerability: SQL injection if the 'query' parameter contains SQL control characters or statements
    snprintf(sql_query, sizeof(sql_query), "SELECT * FROM products WHERE name='%s'", query);
    // Database query execution logic...
    printf("Executing SQL Query: %s\n", sql_query);
}

// Example usage:
// handle_http_query("' OR '1'='1"); // This input can manipulate the SQL query