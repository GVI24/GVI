void extract_and_store_stats(struct net_stats *stats, struct user_stats *user) {
    struct stats_snapshot snapshot;
    snapshot.bytes_received = ntohl(stats->rx_bytes);
    snapshot.bytes_sent = ntohl(stats->tx_bytes);
    snapshot.packets_received = ntohl(stats->rx_packets);
    snapshot.packets_sent = ntohl(stats->tx_packets);

    // Direct copy without checking buffer bounds
    store_stats_snapshot(user, &snapshot, sizeof(snapshot));
}

