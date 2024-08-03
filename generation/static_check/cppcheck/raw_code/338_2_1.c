int calculate_scaling_factor(const VIDEO_QUALITY *vq, int enhancement_level) {
    int base_scale = vq->base_scale;
    int scale = base_scale * enhancement_level * enhancement_level / 50;
    if (scale < base_scale) {
        // Potential underflow or overflow
    }
    return scale;
}

