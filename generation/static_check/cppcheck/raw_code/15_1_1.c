static void update_client_status(client_info *cinfo, tvbuff_t *tvb, int offset) {
    status_data sd;
    status_data *existing_sd;

    sd.status_code = tvb_get_ntohl(tvb, offset);
    sd.status_info = tvb_get_ptr(tvb, offset + 4, -1);  // Potential buffer overflow
    existing_sd = (status_data *)g_hash_table_lookup(status_table, &sd);

    if (existing_sd) {
        g_hash_table_remove(status_table, existing_sd);
        g_free(existing_sd->status_info);  // Potential double free
        g_free(existing_sd);
    } else {
        // Handle new status data...
    }
}

