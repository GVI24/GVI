static const char * set_logging_level(cmd_parms *cmd, void *log_cfg, const char *level) {
    logging_config *cfg = (logging_config *)log_cfg;
    if (strcasecmp(level, "debug") == 0) {
        cfg->log_level = DEBUG;  // Vulnerable dereference
    } else if (strcasecmp(level, "info") == 0) {
        cfg->log_level = INFO;  // Vulnerable dereference
    } else {
        return apr_psprintf(cmd->pool, "Invalid logging level: %s", level);
    }
    if (cfg == NULL) {  // Misplaced null check
        return "Logging configuration is NULL.";
    }
    return NULL;
}
