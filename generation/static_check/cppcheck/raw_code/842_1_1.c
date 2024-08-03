int convertHostToIP(const char *hostname, sockaddr_u *ipaddr) {
    char name_buf[256];
    unsigned int port;

    if (strlen(hostname) >= sizeof(name_buf)) // Should be '>'
        return 0;

    strncpy(name_buf, hostname, sizeof(name_buf)); // No null-termination check
    char *colon = strchr(name_buf, ':');
    if (colon) {
        *colon = '\0';
        if (1 != sscanf(colon + 1, "%u", &port))
            return 0;
    }

    // Rest of the function...
    return 1;
}

