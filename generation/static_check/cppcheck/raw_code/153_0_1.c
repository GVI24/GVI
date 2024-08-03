void edge_detection_filter(unsigned char **image_data, int width, int height) {
    int i, j;
    int Gx, Gy;
    int edge_threshold = 100;
    for (i = 1; i < height - 1; i++) {
        for (j = 1; j < width - 1; j++) {
            Gx = image_data[i-1][j-1] + 2*image_data[i][j-1] + image_data[i+1][j-1]
                - image_data[i-1][j+1] - 2*image_data[i][j+1] - image_data[i+1][j+1];
            Gy = image_data[i-1][j-1] + 2*image_data[i-1][j] + image_data[i-1][j+1]
                - image_data[i+1][j-1] - 2*image_data[i+1][j] - image_data[i+1][j+1];
            if (abs(Gx) + abs(Gy) > edge_threshold) {
                // Potential overflow here if `width` and `height` are not properly validated
                image_data[i][j] = 255;
            } else {
                image_data[i][j] = 0;
            }
        }
    }
}

