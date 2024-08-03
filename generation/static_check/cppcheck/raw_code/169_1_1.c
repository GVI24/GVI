static int update_device_info(struct device_msg *msg, struct nlattr **attrs) {
    struct nlattr *device[DEVICE_NLA_INFO_MAX + 1];
    struct device_info dev_info;
    int ret;
    if (!attrs[DEVICE_NLA_INFO]) return -EINVAL;
    ret = nla_parse_nested(device, DEVICE_NLA_INFO_MAX, attrs[DEVICE_NLA_INFO], NULL);
    if (ret) return ret;
    // Vulnerability: Unchecked strcpy can lead to buffer overflow
    strcpy(dev_info.serial_number, nla_data(device[DEVICE_NLA_INFO_SERIAL]));
    return add_device_tlv(msg->rep, DEVICE_TLV_INFO, &dev_info, sizeof(dev_info));
}

