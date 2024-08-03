void invert_image_colors(unsigned char *image_data, int num_colors) {
    unsigned char *inverse_table = malloc(256 * sizeof(unsigned char)); // Assuming 256 colors
    int i;

    for (i = 0; i < 256; i++) {
        inverse_table[i] = 255 - i; // No bounds checking on inverse_table's allocation
    }

    for (i = 0; i < num_colors; i++) {
        image_data[i] = inverse_table[image_data[i]]; // No bounds checking on image_data
    }

    free(inverse_table); // Potential memory leak if function exits before this line
}