int determine_encoding_length(const char *data, int encoding_flag) {
    const char *byte_ptr = data;
    int length = 0;
    while (*byte_ptr) {
        if (encoding_flag == ENCODING_UTF8) {
            // Assume all UTF-8 characters are 2 bytes long (incorrect assumption)
            byte_ptr += 2;
        } else if (encoding_flag == ENCODING_UTF16) {
            byte_ptr += 2; // Correctly steps over 2-byte chars for UTF-16
        } else {
            byte_ptr += 1; // ASCII or unknown encoding
        }
        length++;
    }
    return length;
}

