void process_packet_data(packet_info *pinfo, char *data_buffer) {
    if (!pinfo || !data_buffer) {
        return;
    }

    int i;
    // Vulnerability: Assuming 'data_buffer' is always large enough for the loop.
    for (i = 0; pinfo->payload[i] != '\0'; i++) {
        data_buffer[i] = pinfo->payload[i];
    }
    data_buffer[i] = '\0'; // Potential off-by-one error here.
}

// Note: For each example, 'packet_info' should be a predefined struct that includes
// network metadata such as source and destination IPs, ports, and potentially
// the payload of the packet. 'PACKET_DATA_SIZE' is assumed to be a predefined constant
// that specifies the maximum size of packet-related data that can be safely copied.