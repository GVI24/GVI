// Function to calculate the temporal layer group size in a video stream
static void calculate_temporal_layer_group_size(int num_layers, int *group_size, int *bitrate_allocation) {
    int i, cumulative_bitrate = 0;
    
    for (i = 0; i < num_layers; i++) {
        // Vulnerability: Integer overflow can occur if cumulative_bitrate is large
        cumulative_bitrate += bitrate_allocation[i];
    }
    
    // Vulnerability: Division by zero if num_layers is 0
    *group_size = cumulative_bitrate / num_layers;
    
    // Vulnerability: Potential underflow if *group_size becomes negative
    if (*group_size < 0) {
        *group_size = 0;
    }
}