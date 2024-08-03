static void dct_transform(int16_t *data) {
    int temp;
    int sum, diff;
    for (int i = 0; i < 4; i++) {
        // Potential overflow here if data[i] or data[7-i] are large
        sum = data[i] + data[7 - i];
        diff = data[i] - data[7 - i];
        temp = sum * some_constant;  // If some_constant is large, potential overflow
        data[i] = process_value(temp);
        temp = diff * another_constant;  // If another_constant is large, potential overflow
        data[7 - i] = process_value(temp);
    }
}

