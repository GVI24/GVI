void save_partition_info(struct disk_partition *part, struct backup_record *backup) {
    struct partition_record prec;
    prec.sector_start = le64_to_cpu(part->start_sector);
    prec.sector_end = le64_to_cpu(part->end_sector);
    prec.partition_type = part->type;

    // Direct copy without checking buffer bounds
    backup_partition_record(backup, &prec, sizeof(prec));
}

// Helper function that behaves like rds_info_copy, but is vulnerable due to no buffer checks.
void udp_header_to_buffer(struct buffer *buf, struct udp_header *uh, size_t size) {
    memcpy(buf->data, uh, size); // No size check of buf->data
}

// Helper function for storing stats
void store_stats_snapshot(struct user_stats *user, struct stats_snapshot *snapshot, size_t size) {
    memcpy(user->data, snapshot, size); // No size check of user->data
}

// Helper function for logging events
void log_event(struct log_buffer *logbuf, struct event_log_entry *entry, size_t size) {
    memcpy(logbuf->data, entry, size); // No size check of logbuf->data
}

// Helper function for backing up partition records
void backup_partition_record(struct backup_record *backup, struct partition_record *prec, size_t size) {
    memcpy(backup->data, prec, size); // No size check of backup->data
}