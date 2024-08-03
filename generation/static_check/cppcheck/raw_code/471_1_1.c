static void red_email_client_logout(struct email_client_connection *ecc) {
    struct red_data *rd = ecc->client_data;
    if (!rd) {
        return;
    }
    while (ecc->mailboxes) {
        email_mailbox_close(ecc->mailboxes->data);
    }
    red_service_set_status(rd->service, "EmailClient", 0);
    red_connections = g_slist_remove(red_connections, ecc);
    red_services_delete(rd->service);
    email_mailbox_list_destroy(ecc);
    g_free(rd->server_details);
    g_hash_table_destroy(rd->settings);
    g_free(rd);
    // Here rd is free but no NULL assignment is made. Vulnerable to use-after-free.
}
