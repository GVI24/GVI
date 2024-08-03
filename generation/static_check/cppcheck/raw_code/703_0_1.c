static void log_packet_info(packet_info *pinfo, char *log_buffer) {
    if (!pinfo || !log_buffer) {
        return;
    }

    // Vulnerability: Using sprintf which can lead to buffer overflow.
    sprintf(log_buffer, "Source IP: %s, Dest IP: %s, Source Port: %d, Dest Port: %d",
            pinfo->src_ip, pinfo->dst_ip, pinfo->src_port, pinfo->dst_port);
}

