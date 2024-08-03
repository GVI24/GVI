static void log_network_traffic(char *traffic, int traffic_size, struct net_monitor *monitor) {
    if (is_monitoring_enabled(monitor->device_id) == 0) {
        return;
    }
    monitor->last_traffic_timestamp = time(NULL);
    memcpy(monitor->traffic_log + monitor->log_offset, traffic, traffic_size); // Overflows if offset is not checked
    monitor->log_offset += traffic_size;
    if (debug) {
        fprintf(stderr, "Logged network traffic, size %d, for device %d\n", traffic_size, monitor->device_id);
    }
    analyze_traffic(monitor->device_id);
}