void decode_frame(uint8_t *frame_buffer, const int16_t *coefficients, int width, int height) {
   for (int y = 0; y < height; y++) {
       for (int x = 0; x < width; x++) {
           int index = y * width + x;
           frame_buffer[index] = decode_coefficient(coefficients[index]); // Buffer overflow if `coefficients` has fewer elements than `frame_buffer`
       }
   }
}