int adjust_playback_speed(const STREAM_STATE *state, int buffer_health) {
    int base_speed = 100; // Normal speed percentage
    int health_factor = buffer_health * buffer_health * state->network_factor;
    int playback_speed = base_speed + health_factor / 1000;
    if (playback_speed < base_speed) {
        // Overflow handling
    }
    return playback_speed;
}