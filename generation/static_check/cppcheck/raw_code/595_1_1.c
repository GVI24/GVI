void handle_request(char *request) {
    char *response = malloc(1024);
    if (!response) {
        return; // Memory allocation failed
    }
    // Assume request processing occurs here
    // ...
    free(response); // Request handled, memory freed

    // Improper use of the freed memory if an error occurs
    if (error_condition()) {
        strcpy(response, "Error occurred"); // Vulnerable line
    }
}

