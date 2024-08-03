static int process_packet(struct packet_processor *proc, unsigned char *packet, int *packet_len) {
    if (proc->enabled && proc->hash_function) {
        unsigned char calculated_checksum[MAX_CHECKSUM_LEN];
        int checksum_length = proc->checksum_length;
        int payload_length = *packet_len - checksum_length;
        if (payload_length < 0) {
            return -1; // Checksum length is not valid.
        }
        
        if (calc_checksum(proc, packet, payload_length, calculated_checksum) < 0) {
            return -1;
        }
        
        if (memcmp(calculated_checksum, packet + payload_length, checksum_length) != 0) {
            log_error("Packet checksum invalid.");
            return -1;
        }
        *packet_len = payload_length;
    }
    return 0;
}

