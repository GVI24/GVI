void store_device_data(char *data, int data_len, struct device *dev) {
    char log_entry[1024];
    if (data_len < 0) return;
    if (!dev->is_registered) return;
    if (strlen(data) != data_len) return; // Incorrect assumption, could be non-null-terminated

    // Vulnerable: log_entry can be overflowed if data_len exceeds 1024
    memcpy(log_entry, data, data_len);
    log_device_activity(dev, log_entry);
}