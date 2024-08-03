void track_packets(struct packet_tracker * tracker, struct packet * pkt) {
    struct packet ** tracked_packets;
    size_t index = 0;
    tracked_packets = malloc(15 * sizeof(struct packet*));
    for (size_t i = 0; i < tracker->max_packets; i++) {
        if (tracker->packets[i] && tracker->packets[i]->protocol == pkt->protocol) {
            tracked_packets[index++] = tracker->packets[i]; // No bounds check, overflow risk
        }
    }
    tracked_packets[index] = NULL; // Null-terminate the array
}