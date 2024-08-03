// Potential Vulnerability: Integer Overflow and Lack of Null Check
void adjust_brightness(VideoSettings *settings, int increase_by) {
    int new_brightness;
    if (settings->brightness + increase_by > MAX_BRIGHTNESS || settings->brightness + increase_by < MIN_BRIGHTNESS) {
        // Handle out of bounds brightness...
        return;
    }
    // Flawed logic that can cause integer overflow if 'increase_by' is very large.
    new_brightness = settings->brightness + increase_by;
    settings->brightness = new_brightness;
}
