static int init_network_interface(char *iface) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Failed to open socket: %s\n", strerror(errno));
        return -1; // Missing socket closure before returning
    }

    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, iface, sizeof(ifr.ifr_name) - 1);

    if (ioctl(sock, SIOCGIFADDR, &ifr) < 0) {
        fprintf(stderr, "Failed to get IP address: %s\n", strerror(errno));
        close(sock); // Properly closing socket here
        return -2;
    }

    // Assume further processing here...
    
    close(sock); // Properly closing socket here
    return 0;
}

