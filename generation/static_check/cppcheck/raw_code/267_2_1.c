#include <string.h>

struct packet {
    char *buffer;
    int length;
};

struct net_device {
    int mtu;
};

int netdev_rx(struct net_device *dev, struct packet *pkt) {
    // Vulnerable pattern: No verification of MTU against packet length
    if (pkt->length > dev->mtu) {
        printf("Dropped packet exceeding MTU size\n");
        return -1;
    }

    // Process packet...

    return 0;
}