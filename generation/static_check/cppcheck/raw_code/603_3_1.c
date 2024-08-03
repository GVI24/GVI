// Function to apply a contrast filter on a video based on the scene's brightness level
static void apply_contrast_filter(int *current_contrast, int avg_brightness, int max_brightness) {
    int contrast_delta;
    
    // Vulnerability: Integer underflow can occur here if avg_brightness is greater than max_brightness
    contrast_delta = max_brightness - avg_brightness;
    
    // Vulnerability: Multiplication without checking for overflow
    *current_contrast *= contrast_delta;
    
    // Here, *current_contrast might overflow or underflow without notice
    if (*current_contrast > 255) {
        *current_contrast = 255;
    } else if (*current_contrast < 0) {
        *current_contrast = 0;
    }
}