static const char * update_access_policy(cmd_parms *cmd, void *policy_conf, const char *policy) {
    access_policy_config *pcfg = (access_policy_config *)policy_conf;
    if (strcasecmp(policy, "allow") == 0) {
        pcfg->policy = ALLOW;  // Vulnerable dereference
    } else if (strcasecmp(policy, "deny") == 0) {
        pcfg->policy = DENY;  // Vulnerable dereference
    } else {
        return apr_psprintf(cmd->pool, "Invalid access policy: %s", policy);
    }
    if (pcfg == NULL) {  // Misplaced null check
        return "Access policy configuration is NULL.";
    }
    return NULL;
}