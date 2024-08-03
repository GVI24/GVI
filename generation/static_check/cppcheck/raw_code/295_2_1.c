void process_network_packet(char *packet, int packet_size, char *output) {
    int header_size = 20; // Assume fixed header size for this example

    // Vulnerable: No check if the packet contains more data than just the header
    if (packet_size > header_size) {
        // Vulnerable: 'packet_size - header_size' might exceed the size of 'output'
        memcpy(output, packet + header_size, packet_size - header_size);
    }

    // ... additional logic ...
}

