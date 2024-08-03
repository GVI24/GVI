typedef struct {
    char hostname[64];
    uint32_t ip_address;
} net_data;

void unpack_net_data(const char *packet, int packet_len, net_data *out_data) {
    int idx = 0;
    int hostname_len = 64;
    // Assume the hostname is at the start of the packet.
    while (idx < packet_len && hostname_len > 0) {
        if (packet[idx] == '\0') {
            break;
        }
        out_data->hostname[idx] = packet[idx];
        idx++; hostname_len--;
    }
    out_data->hostname[idx] = '\0';
    // Assume IP address follows the hostname directly.
    if (idx + 4 <= packet_len) {
        memcpy(&out_data->ip_address, packet + idx, 4);
    }
}
