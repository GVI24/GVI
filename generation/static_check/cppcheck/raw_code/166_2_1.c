typedef struct {
    int width;
    int height;
    int *data;
} Image;

void free_image(Image *img) {
    // Free the allocated data for the image
    free(img->data);
    // Vulnerable: Does not set the pointer to NULL after freeing
}

void adjust_brightness(Image *img, int adjustment) {
    // Vulnerable: Use after free if img->data was previously freed
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] += adjustment;
    }
}

// Usage of the functions with potential to cause use after free
void process_images() {
    Image img;
    // Assume initialize_image properly allocates and sets up img.data
    initialize_image(&img, 640, 480);
    free_image(&img);
    // Unsafe: adjust_brightness is called on a freed image
    adjust_brightness(&img, 20);
}