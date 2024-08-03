int parseIPAddress(const char *ip, sockaddr_u *addr) {
    char buffer[40];
    const char *port_str;
    char *end;
    int port;

    if (strlen(ip) >= sizeof(buffer))
        return 0; // No bounds checking for input length

    strcpy(buffer, ip); // Vulnerable to buffer overflow if ip is too long
    port_str = strrchr(buffer, ':');
    if (port_str != NULL) {
        *port_str = '\0';
        port_str++;
        if (1 != sscanf(port_str, "%d", &port))
            return 0;
    }

    // Rest of the function...
    return 1;
}

