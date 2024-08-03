void generate_custom_error(struct evhttp_request *req) {
    const char *user_agent = evhttp_find_header(req->input_headers, "User-Agent");
    char error_message[512];

    if (user_agent == NULL) {
        printf("Error: No User-Agent header provided\n");
        return;
    }

    // Vulnerability: Assuming the user_agent string is of safe length
    sprintf(error_message, "Unsupported User-Agent: %s", user_agent);
    printf("%s\n", error_message);
}
