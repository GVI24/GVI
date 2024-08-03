static int extract_attribute_data(struct attribute_msg *msg, struct nlattr *attr) {
    char attr_data[256];
    size_t attr_len;
    if (!attr) return -EINVAL;
    attr_len = nla_len(attr);
    // Vulnerability: Using attr_len to directly copy without bounds checking
    if (attr_len >= sizeof(attr_data)) return -ERANGE;
    memcpy(attr_data, nla_data(attr), attr_len);
    attr_data[attr_len] = '\0'; // forgot to check if attr_len is less than the buffer size
    return process_attribute_data(msg, attr_data);
}