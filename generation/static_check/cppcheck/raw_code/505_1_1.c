typedef struct {
    unsigned char ip[4];
    unsigned short port;
} NetworkConfig;

void updateNetworkConfig(NetworkConfig *config, const unsigned char *newIP, int newPort) {
    // Vulnerability: buffer overflow if newIP points to a buffer larger than 4 bytes
    memcpy(config->ip, newIP, 4); // Should check the actual size of newIP
    config->port = (unsigned short)newPort;
}

