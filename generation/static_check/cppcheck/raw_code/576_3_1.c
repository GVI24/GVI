static int handle_new_server(struct Client *client_p, const char *servername) {
    if (servername == NULL || client_p == NULL) return 0;

    char id[IDLEN];
    if (strlen(servername) > IDLEN - 1) {
        // Server name too long, but not safely handled
        return -1;
    }
    strcpy(id, servername); // Potential buffer overflow

    // Further code to initialize server connection and synchronization
    // ...
    return 1;
}