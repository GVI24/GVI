static const char * configure_timeout(cmd_parms *cmd, void *config, const char *timeout_str) {
    service_config *svc_cfg = (service_config *)config;
    svc_cfg->timeout = strtol(timeout_str, NULL, 10);  // Vulnerable dereference
    if (svc_cfg == NULL) {
        return "Service configuration is NULL.";
    }
    if (svc_cfg->timeout < 0) {
        return apr_psprintf(cmd->pool, "Timeout value must not be negative: %s", timeout_str);
    }
    return NULL;
}
