int estimate_bits_for_motion(const MOTION_DATA *motion_data, int frame_count) {
    if (frame_count <= 0) {
        return 0;
    } else {
        int motion_factor = motion_data->motion_factor;
        // Potential overflow when calculating bits_per_frame
        int bits_per_frame = (motion_factor * frame_count) << 4;
        return bits_per_frame;
    }
}

