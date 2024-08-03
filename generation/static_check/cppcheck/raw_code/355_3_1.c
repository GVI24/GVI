void add_user(char *userinfo) {
    char *query = (char *)malloc(1024);
    // Vulnerability: no bounds checking against the length of userinfo
    sprintf(query, "INSERT INTO users VALUES ('%s')", userinfo);
    // ... Code to execute query
    free(query); // Freeing memory to avoid memory leak
}

