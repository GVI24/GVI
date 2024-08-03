typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

int calculate_motion(Image *current, Image *reference, int *motion_x, int *motion_y) {
    int width = current->width;
    int height = current->height;
    
    // Vulnerable: Integer overflow can occur when calculating the offset
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int offset = i * width + j; // May overflow for large width and height
            int reference_offset = (i + *motion_x) * width + (j + *motion_y); // May overflow
            
            // Simulating comparison of image blocks
            if (current->data[offset] != reference->data[reference_offset]) {
                return 0; // Motion detected
            }
        }
    }
    return 1; // No motion
}