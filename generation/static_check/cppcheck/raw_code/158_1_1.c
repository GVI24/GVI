void handle_client_input(struct evhttp_request *req) {
    char *client_data = (char *)req->input_buffer;
    char response[256];

    if (client_data == NULL) {
        printf("No input from client\n");
        return;
    }

    // Vulnerable: unbounded copy into fixed-size buffer
    strcpy(response, "Client said: ");
    strcat(response, client_data);
    printf("%s\n", response);
}
