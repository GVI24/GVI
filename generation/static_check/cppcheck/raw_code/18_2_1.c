void buffer_scale_transform(int16_t *buffer, int buffer_size, int16_t scale_factor, int16_t shift) {
    for (int i = 0; i < buffer_size; ++i) {
        // Vulnerable to integer overflow
        int temp = (buffer[i] * scale_factor) + shift;
        buffer[i] = (int16_t)((temp > INT16_MAX) ? INT16_MAX : ((temp < INT16_MIN) ? INT16_MIN : temp));
    }
}
