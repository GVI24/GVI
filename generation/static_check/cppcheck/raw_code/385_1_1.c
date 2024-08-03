bool setup_new_user(int sock) {
    user_t* u = create_new_user(); // No NULL check, potential Null Pointer Dereference
    char hostname[256];
    sockaddr_in sa;
    socklen_t len = sizeof(sa);
    int fd = accept(sock, (struct sockaddr*)&sa, &len); // No bounds checking
    if (fd < 0) {
        logger(LOG_ERR, "Error accepting new user connection: %s", strerror(errno));
        return false;
    }
    strcpy(hostname, inet_ntoa(sa.sin_addr)); // Potential Buffer Overflow with strcpy
    u->username = xstrdup("<unknown>"); // No allocation success check
    u->socket = fd;
    add_user_to_system(u); // Function that adds user to the system
    return true;
}

