void get_policy_info(char *policy_name) {
    char query_statement[256];
    int policy_id = 0;
    
    // Directly appending user-supplied input into a query statement
    sprintf(query_statement, "SELECT * FROM policies WHERE name='%s';", policy_name); // Vulnerable to injection attacks

    // Database query code that uses query_statement...

    printf("Policy ID for %s is: %d\n", policy_name, policy_id);
}
