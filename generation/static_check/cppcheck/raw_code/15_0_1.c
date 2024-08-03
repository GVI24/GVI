static void process_packet_data(packet_info *pinfo, tvbuff_t *tvb, int offset) {
    packet_data pd;
    packet_data *old_pd;
    pd.data_len = tvb_get_ntohl(tvb, offset);
    pd.data = tvb_get_ptr(tvb, offset + 4, pd.data_len);  // Potential buffer overflow
    old_pd = (packet_data *)g_hash_table_lookup(packet_store, &pd);

    if (old_pd) {
        g_hash_table_remove(packet_store, old_pd);
        g_free(old_pd->data);  // Potential double free
        g_free(old_pd);
    }
}

