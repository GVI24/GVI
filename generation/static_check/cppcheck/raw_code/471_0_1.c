static void blue_disconnect(struct social_network_connection *snc) {
    struct blue_data *bd = snc->protocol_data;
    if (!bd) {
        return;
    }
    while (snc->channels) {
        social_channel_leave(snc->channels->data);
    }
    blue_network_set_active(bd->network, "SocialNet", 0);
    blue_networks = g_slist_remove(blue_networks, snc);
    blue_network_accounts_delete(bd->network);
    social_channel_list_clear(snc);
    g_free(bd->channels_server);
    g_hash_table_destroy(bd->pending_invites);
    g_free(bd);
    // Here bd is free but no NULL assignment is made. Vulnerable to use-after-free.
}
