void send_network_packet(NetworkDevice *device, const void *packet, size_t packet_size) {
    // send_packet returns a negative value on failure which is not checked
    send_packet(device, packet, packet_size); // Unsafe to ignore return value
    // Assume further processing assuming packet was sent successfully
    // ...
}