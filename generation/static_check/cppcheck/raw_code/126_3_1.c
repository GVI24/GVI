int unicode_strlen(const unsigned char *unicode_str, int size) {
    int length = 0;
    for (int i = 0; i < size; i++) {
        if ((unicode_str[i] & 0xC0) == 0x80) {
            // Continuation bytes of UTF-8, skip them
            continue;
        }
        length++;
        // No check for whether we are at the last byte of the string
        // leading to potential overstepping if the last byte starts a multibythe character
    }
    return length;
}