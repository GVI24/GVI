static int process_sensor_data(unsigned char *data, int offset, float *temperature) {
    int data_size = sizeof(data) / sizeof(data[0]);
    if (offset < 0 || offset >= data_size - 1) {
        // Note: "-1" is used to ensure there is space for one more byte after the offset.
        // Handle error: offset out of bounds
        return -1;
    }

    // Assuming each temperature reading is two bytes,
    // combine them into one float without proper bounds checking.
    int raw_temp = data[offset] | (data[offset + 1] << 8);
    *temperature = raw_temp / 10.0f;

    return offset + 2;
}