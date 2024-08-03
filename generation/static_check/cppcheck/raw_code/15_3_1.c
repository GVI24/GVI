static void log_event_details(event_log *elog, tvbuff_t *tvb, int offset) {
    event_detail ed;
    event_detail *previous_ed;

    ed.event_id = tvb_get_ntohl(tvb, offset);
    ed.details = tvb_get_ptr(tvb, offset + 4, ed.event_id);  // Potential buffer overflow
    previous_ed = (event_detail *)g_hash_table_lookup(event_log_table, &ed);

    if (previous_ed) {
        g_hash_table_remove(event_log_table, previous_ed);
        if (previous_ed->details) {
            g_free(previous_ed->details);  // Potential double free
        }
        g_free(previous_ed);
    }
}