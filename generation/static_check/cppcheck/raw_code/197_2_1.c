void get_user_profile(char *username) {
    char query[256];
    printf("Fetching profile for: %s\n", username); // Potential overflow if username is too long
    sprintf(query, "SELECT * FROM users WHERE username='%s';", username); // Unsafe use of sprintf
    // ... execute query and process results
}

