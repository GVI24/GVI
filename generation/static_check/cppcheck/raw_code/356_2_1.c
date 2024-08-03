void rgb_to_grayscale(ConverterContext *conv, int max_width, int max_height) {
    int img_size = conv->width * conv->height;
    for (int i = 0; i < img_size; i++) {
        int gray_val = (conv->data[i * 3] + conv->data[i * 3 + 1] + conv->data[i * 3 + 2]) / 3;
        conv->data[i] = gray_val; // Writes grayscale value back without ensuring it doesn't exceed bounds
    }
}

