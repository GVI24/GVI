// Function to scale video frames based on bitrate changes
static void scale_video_frames(int initial_bitrate, int *target_bitrate, int *num_frames) {
    int bitrate_delta, scaled_frames;
    
    // Vulnerability: Integer overflow can occur here
    bitrate_delta = *target_bitrate - initial_bitrate;
    
    // Vulnerability: Division by zero if initial_bitrate is 0
    scaled_frames = (*num_frames * bitrate_delta) / initial_bitrate;
    
    // Vulnerability: Potential underflow if scaled_frames becomes negative
    if (scaled_frames < 0) {
        scaled_frames = 0;
    }
    
    *num_frames = scaled_frames;
}