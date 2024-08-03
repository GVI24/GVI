void prepare_packet_header(NETWORK_PACKET *packet, const unsigned char *header_data, int header_size) {
    // header_size is the size of the header data to be copied into the packet
    // If header_size is larger than the allocated size of packet->header, buffer overflow can occur
    vpx_memcpy(packet->header, header_data, header_size);
    
    // Set other packet header fields...
}