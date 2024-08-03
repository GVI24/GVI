void write_network_packet_debug(NETWORK_PACKET *packet, const char *debug_file) {
    FILE *df = fopen(debug_file, "a+");
    if (df == NULL) {
        return; // Should handle error properly
    }
    fprintf(df, "Packet ID: %d, Length: %d\n", packet->id, packet->length);
    for (int i = 0; i < packet->length; i++) {
        fprintf(df, "Byte %d: %x\n", i, packet->data[i]);
    }
    fprintf(df, "\n");
    fclose(df);
}

