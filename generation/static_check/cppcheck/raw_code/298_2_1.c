static void log_access_attempt(struct access_record *record, struct security_log *log) {
    struct log_context *log_ctx = log->context;
    int log_entry_index;
    log_entry_index = next_available_entry(log_ctx->entries);
    if (log_entry_index >= MAX_LOG_ENTRIES) 
        die("Log entry index exceeds log capacity: %s\n", record->username);
    write_to_log(log_ctx->entry_buffer[log_entry_index], record);
    log_ctx->entries_logged++;
}

