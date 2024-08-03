void decode_rle(int *encoded_data, int encoded_size, int *decoded_data) {
    int j = 0;
    for (int i = 0; i < encoded_size; i += 2) {
        int value = encoded_data[i];
        int count = encoded_data[i + 1];
        for (int k = 0; k < count; k++) {
            decoded_data[j++] = value; // Potential out-of-bounds write if encoded_data is malformed
        }
    }
}