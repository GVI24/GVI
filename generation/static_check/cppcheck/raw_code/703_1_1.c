static void create_packet_summary(packet_info *pinfo, char *summary) {
    if (!pinfo || !summary) {
        return;
    }

    strcpy(summary, "Packet Summary:\n");
    
    // Vulnerability: Not checking remaining buffer space can overflow 'summary'.
    strcat(summary, "SRC IP: ");
    strcat(summary, pinfo->src_ip);
    strcat(summary, "\nDST IP: ");
    strcat(summary, pinfo->dst_ip);
    strcat(summary, "\nPayload:");
    strcat(summary, pinfo->payload);
}

