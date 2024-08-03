void decode_audio_samples(const char *encoded_data, int data_length, char *decoded_samples, int max_length) {
    int processed_length = 0;

    // Vulnerable loop: May write past the 'decoded_samples' buffer if not correctly bounded
    while (processed_length < data_length) {
        // ... some decoding logic ...

        // Vulnerable: No check to ensure 'decoded_length' is within 'max_length'
        int decoded_length = decode(encoded_data + processed_length, decoded_samples + processed_length);

        processed_length += decoded_length;
    }

    // ... additional logic ...
}

// Helper function for example 4, stubbed as the decoding functionality is not the focus
int decode(const char *input, char *output) {
    // Pretend to decode data and return length of decoded data
    int dummy_decoded_length = 50; // Dummy value for the example
    strncpy(output, input, dummy_decoded_length);
    return dummy_decoded_length;
}