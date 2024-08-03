#include <string.h>

typedef struct {
    unsigned int length;
    unsigned char data[];
} UDPDatagram;

void process_udp_datagram(char *packet_buffer, int packet_size, unsigned char *data_output, int data_output_size) {
    UDPDatagram *datagram = (UDPDatagram *)packet_buffer;
    unsigned int data_length = datagram->length;

    // Vulnerability: no check to ensure data_length is less than data_output_size
    memcpy(data_output, datagram->data, data_length);
}