static const char * set_max_clients(cmd_parms *cmd, void *server_conf, const char *value) {
    server_config *s_cfg = (server_config *)server_conf;
    int max_clients = atoi(value);
    s_cfg->max_clients = max_clients;  // Vulnerable dereference
    if (s_cfg == NULL) {
        return "Server configuration structure is NULL.";
    }
    if (max_clients <= 0) {
        return apr_psprintf(cmd->pool, "Invalid number of max clients: %s", value);
    }
    return NULL;
}
