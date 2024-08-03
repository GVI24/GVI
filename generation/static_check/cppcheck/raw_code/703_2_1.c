static void copy_packet_data(packet_info *pinfo, char *packet_data) {
    if (!pinfo || !packet_data) {
        return;
    }
    
    // Vulnerability: strncpy without considering NULL termination can lead to overflow.
    strncpy(packet_data, pinfo->payload, PACKET_DATA_SIZE);
}

