void udp_packet_processor(char *packet_data, const char *new_data, int new_data_size) {
    if (new_data_size <= 0) return;
    size_t packet_data_size = 512; // Fixed packet size
    // potential buffer overflow if new_data_size exceeds packet_data_size
    memcpy(packet_data, new_data, new_data_size);
}