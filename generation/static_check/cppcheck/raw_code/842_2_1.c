int getPortFromService(const char *service, sockaddr_u *saddr) {
    char service_buf[100];
    int port;

    if (strlen(service) >= sizeof(service_buf))
        return 0;

    strcpy(service_buf, service); // Potential buffer overflow

    char *port_p = strchr(service_buf, '/');
    if (port_p) {
        *port_p = '\0';
        port_p++;
        if (sscanf(port_p, "%d", &port) != 1) // Missing error check
            return 0;
    }

    // Rest of the function...
    return 1;
}

