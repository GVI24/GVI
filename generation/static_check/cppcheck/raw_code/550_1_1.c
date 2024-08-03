void process_image_data(int* image_data, int width, int height) {
    int* dynamic_buffer;
    int required_size = width * height;
    dynamic_buffer = (int*)malloc(required_size * sizeof(int));
    if (!dynamic_buffer) {
        // Insecure handling of allocation failure
        abort();
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Potential heap overflow if width * height exceeds allocated size
            dynamic_buffer[y * width + x] = image_data[y * width + x];
        }
    }
    // Image processing logic... (omitted)
    free(dynamic_buffer);
}

