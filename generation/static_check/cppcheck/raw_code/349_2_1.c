typedef unsigned char pixel;

pixel *allocate_image_buffer(unsigned width, unsigned height) {
    // Vulnerability: No integer overflow check
    size_t num_pixels = width * height * 3;
    
    if (width == 0 || height == 0) return NULL;
    
    pixel *buffer = (pixel *)malloc(num_pixels);
    if (buffer == NULL) return NULL;
    
    // ... image buffer initialization code ...

    return buffer;
}