// Function to compute buffer size needed for a frame at a particular quality level
static void compute_buffer_size(int quality_index, int frame_width, int frame_height, int *buffer_size) {
    // Vulnerability: Integer overflow can occur here
    int base_size = frame_width * frame_height;
    
    // Vulnerability: Division by zero if quality_index is 0
    *buffer_size = base_size / quality_index;
    
    // Vulnerability: Incorrect calculation if base_size overflows and becomes negative
    if (*buffer_size < 0) {
        *buffer_size = 0;
    }
}