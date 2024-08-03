void encode_samples_4(unsigned char *samples, int *lookup, int total_samples) {
    int i;
    unsigned char encoded[100]; // Static buffer size
    // Vulnerable loop: no check that lookup[i] is within the 'encoded' bounds
    for (i = 0; i < total_samples; i++) {
        int encode_index = lookup[i];
        // Possible buffer overflow if 'lookup[i]' is greater than 99
        encoded[encode_index] = samples[i] % 256;
    }
}