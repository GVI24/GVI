int process_sensor_data(const unsigned char *data, int data_len) {
    int pos = 0;
    while (pos < data_len) {
        int sensor_id = data[pos++];
        int reading_len = data[pos++]; // Possible over-read if pos is last byte.
        if (pos + reading_len > data_len) { // No check for reading_len bound
            return -1;
        }
        // Process sensor reading...
        pos += reading_len;
    }
    return 0;
}

