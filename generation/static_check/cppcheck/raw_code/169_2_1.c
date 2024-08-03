static int handle_config_request(struct config_msg *req, struct nlattr **attrs) {
    struct nlattr *config[CONFIG_NLA_PARAM_MAX + 1];
    char config_value[64];
    int res;
    if (!attrs[CONFIG_NLA_PARAM]) return -EINVAL;
    res = nla_parse_nested(config, CONFIG_NLA_PARAM_MAX, attrs[CONFIG_NLA_PARAM], NULL);
    if (res) return res;
    // Vulnerability: Unchecked strcpy can cause buffer overflow
    strcpy(config_value, nla_data(config[CONFIG_NLA_PARAM_VALUE]));
    return send_back_config_response(req, config_value);
}

