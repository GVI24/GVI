// Function to convert a line of grayscale values to RGB
static void grayscale_to_rgb(uint8_t *dest, const uint8_t *src, int num_pixels) {
    int i;
    // Vulnerability: No bounds checking on src and dest
    for (i = 0; i < num_pixels; i++) {
        uint8_t value = src[i];
        // Assuming RGB data is 3 bytes per pixel: R, G, B
        dest[i * 3] = value;     // Red channel
        dest[i * 3 + 1] = value; // Green channel
        dest[i * 3 + 2] = value; // Blue channel
        // Potential overflow if dest is not large enough
    }
}
