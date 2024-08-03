void custom_codec_decode(uint8_t *encoded_data, uint8_t *decoded_data, int data_length) {
    int i;
    for (i = 0; i < data_length; i += 2) {
        // Assuming encoded_data has pairs of bytes for each decoded byte
        decoded_data[i / 2] = (encoded_data[i] - 1) ^ encoded_data[i + 1];
        // No bounds checking on the input buffer, can read beyond its end
    }
}