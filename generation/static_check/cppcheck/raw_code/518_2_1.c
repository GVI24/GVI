int decode_radio_signal(const unsigned char *signal, int signal_length) {
    char decoded_message[128];
    int i, decode_index = 0;
    for (i = 0; i < signal_length; ++i) {
        if (signal[i] == 0xFF) { // End of signal marker
            break;
        }
        decoded_message[decode_index++] = (char)(signal[i] ^ 0xAA); // XOR-based decoding
        if (decode_index >= sizeof(decoded_message)) { // Buffer overflow vulnerability
            // Improper bounds checking, should stop the loop before overflow
            break;
        }
    }
    decoded_message[decode_index] = '\0'; // Potential off-by-one error
    // Decoded message would be used here...
    return 0;
}