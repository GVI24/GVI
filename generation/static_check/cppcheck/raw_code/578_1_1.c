int image_processor_init(ImageProcessor *ip, int width, int height) {
    assert(ip);

    ip->width = width;
    ip->height = height;

    ip->raw_image = (char *)malloc(width * height * sizeof(char));
    if (!ip->raw_image) {
        // Memory allocation failed, but no cleanup for previously allocated resources
        return -1;
    }

    ip->processed_image = (char *)malloc(width * height * sizeof(char));
    if (!ip->processed_image) {
        // Forgot to free ip->raw_image
        return -1;
    }

    ip->filter_matrix = (float *)malloc(3 * 3 * sizeof(float));
    if (!ip->filter_matrix) {
        // Forgot to free ip->raw_image and ip->processed_image
        return -1;
    }

    memset(ip->filter_matrix, 0, 3 * 3 * sizeof(float));
    return 0;
}

