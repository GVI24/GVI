static void convert_to_grayscale(unsigned char *image, int width, int height, unsigned char *grayscale) {
    int plane;
    unsigned char color_planes[3];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (plane = 0; plane <= 3; plane++) { // Vulnerability: plane should be < 3
                color_planes[plane] = image[(y * width + x) * 3 + plane];
            }
            // Simple average for grayscale conversion
            grayscale[y * width + x] = (color_planes[0] + color_planes[1] + color_planes[2]) / 3;
        }
    }
}

