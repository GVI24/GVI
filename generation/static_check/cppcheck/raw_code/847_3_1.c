static void analyze_packets(NETWORK_STREAM *stream, PACKET_ANALYSIS *analysis, int count) {
    int i;
    PACKET *packet;

    // Loop potentially exceeds bounds of packets array, causing buffer overflow
    for (i = 0; i < count; i++) {
        packet = &stream->packets[i];
        analysis->results[i] = perform_analysis(packet);
    }
}