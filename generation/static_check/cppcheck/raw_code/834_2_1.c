void int_to_hex(int value, char *buffer) {
    char hex_rep[16]; // Fixed size buffer
    int index = 0;
    const char *hex_chars = "0123456789ABCDEF";

    // Convert integer to hex without bounds checking
    do {
        hex_rep[index++] = hex_chars[value & 0xF];
        value >>= 4;
    } while (value && index < sizeof(hex_rep) + 1); // Off-by-one error here

    // Reverse the hex representation into the buffer
    int j = 0;
    while (index-- > 0) {
        buffer[j++] = hex_rep[index];
    }
    buffer[j] = '\0'; // No buffer overflow check
}

