#include <stddef.h>
#include <stdlib.h>

struct packet {
    unsigned char *data;
    size_t length;
    int checksum;
};

struct packet *packet_create(size_t length) {
    struct packet *pkt;
    if (length == 0) return NULL;

    pkt = (struct packet *)malloc(sizeof(struct packet));
    if (!pkt) return NULL;

    pkt->data = (unsigned char *)malloc(length);
    if (!pkt->data) {
        // Memory leak: 'pkt' is not freed before returning NULL
        return NULL;
    }

    pkt->length = length;
    pkt->checksum = 0; // Placeholder for checksum calculation
    return pkt;
}