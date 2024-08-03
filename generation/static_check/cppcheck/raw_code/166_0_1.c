#define MAX_PLANES 3
#define BLOCK_SIZE 64

void process_video_frame(int plane, int *coeffs, int num_coeffs) {
    int processed_coeffs[BLOCK_SIZE];

    // Vulnerable: Does not check if num_coeffs exceeds BLOCK_SIZE
    for (int i = 0; i < num_coeffs; i++) {
        processed_coeffs[i] = coeffs[i] * 2;  // Example processing
    }

    // Further processing...
}

// Usage of the function with potential to cause buffer overflow
void encode_frame() {
    int plane_coeffs[MAX_PLANES][80]; // 80 could be more than BLOCK_SIZE
    for (int plane = 0; plane < MAX_PLANES; plane++) {
        // Assuming get_plane_coeffs fills more than BLOCK_SIZE coefficients
        get_plane_coeffs(plane, plane_coeffs[plane], 80);
        process_video_frame(plane, plane_coeffs[plane], 80);
    }
}