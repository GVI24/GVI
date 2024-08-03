static void create_query(char *user_supplied_filter) {
    char query[512];
    // Vulnerability: user_supplied_filter is directly used in a format function.
    snprintf(query, sizeof(query), "SELECT * FROM data WHERE info = '%s'", user_supplied_filter);
    // Execute query on the database (Pseudo-code)
    execute_database_query(query);
}