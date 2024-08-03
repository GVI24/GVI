
unsigned int hex_to_int(char *hex) {
    unsigned int result = 0;
    int nibble;
    while (*hex) {
        nibble = (*hex <= '9') ? (*hex - '0') : ((*hex & ~0x20) - 'A' + 10); // No validation for non-hex characters
        result = (result << 4) | (nibble & 0xF);
        hex++;
    }
    return result;
}

