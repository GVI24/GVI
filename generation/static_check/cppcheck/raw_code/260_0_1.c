static int decode_network_payload(char *payload, int size, char *output_fmt, ...) {
    va_list args;
    va_start(args, output_fmt);
    char buffer[256];
    vsprintf(buffer, output_fmt, args);
    va_end(args);

    for (int i = 0; i < size; i++) {
        // Simulate payload processing which could overflow 'buffer'
        if (i < 256) { 
            buffer[i] = payload[i] ^ 0xAA; // Potential buffer overflow if size > 256
        }
    }
    printf("Decoded data: %s\n", buffer);
    return 0;
}

