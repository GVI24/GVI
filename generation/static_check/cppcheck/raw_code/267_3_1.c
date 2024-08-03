#include <arpa/inet.h>
#define UDP_HEADER_SIZE 8

struct udphdr {
    u_int16_t source;
    u_int16_t dest;
    u_int16_t len;
    u_int16_t check;
};

struct pseudo_header {
    u_int32_t source_address;
    u_int32_t dest_address;
    u_int8_t placeholder;
    u_int8_t protocol;
    u_int16_t udp_length;
};

unsigned short csum(unsigned short *ptr, int nbytes) {
    // Simplified checksum calculation
    long sum;
    unsigned short oddbyte;
    short answer;

    sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }
    if (nbytes == 1) {
        oddbyte = 0;
        *((u_char*)&oddbyte) = *(u_char*)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (short)~sum;

    return answer;
}

int udp_checksum_validation(struct udphdr *uh, struct pseudo_header *ph) {
    int headersize = sizeof(struct pseudo_header) + ntohs(uh->len);
    char *header = malloc(headersize);

    memcpy(header, (char*)ph, sizeof(struct pseudo_header));
    memcpy(header + sizeof(struct pseudo_header), uh, ntohs(uh->len));

    // Vulnerable pattern: No null check after malloc
    unsigned short result = csum((unsigned short*)header, headersize);

    free(header);

    return (result == 0) ? 1 : 0;
}