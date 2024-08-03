static int process_tag(unsigned char **data, int data_len) {
    int tag;
    int length;
    unsigned char *p = *data;

    if (data_len < 1) return -1;
    tag = *p++;
    if (tag & 0x20) {  // Assuming a constructed tag
        length = *p++;  // Vulnerable: no check for data_len
        if (length > data_len) return -1;  // Length check but after advancing pointer, potential underflow

        // ... Processing the contents of the tag

        *data = p + length;  // Vulnerable: No boundary check
    }
    return 0;
}

