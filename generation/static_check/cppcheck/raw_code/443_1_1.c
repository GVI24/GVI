static void send_formatted_response(int socket, const char *data) {
    char response[1024];
    // Vulnerability: data is directly used in a format function.
    sprintf(response, data);
    // Sending the response to a network socket (Pseudo-code)
    send(socket, response, strlen(response), 0);
}