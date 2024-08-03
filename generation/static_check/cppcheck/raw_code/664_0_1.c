static int parse_config_flag(tvbuff_t *tvb, int offset, guint32 *flag) {
    guint32 config_flag = tvb_get_letohl(tvb, offset);
    switch (config_flag) {
    case CONFIG_ENABLE:
        *flag = CONFIG_ENABLE;
        break;
    case CONFIG_DISABLE:
        *flag = CONFIG_DISABLE;
        break;
    case CONFIG_AUTO:
        *flag = CONFIG_AUTO;
        break;
    case CONFIG_MANUAL:
        *flag = CONFIG_MANUAL;
        break;
    default:
        DISSECTOR_ASSERT(FALSE);  // Vulnerability: Use of assertion
        break;
    }
    return offset + 4;
}

