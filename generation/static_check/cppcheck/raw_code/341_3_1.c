static void correct_frame_offset(DecodeContext *dc, int delta_x, int delta_y) {
    AVFrame *frame = dc->working_frame;
    int corrected_x, corrected_y;
    int offset_x = dc->offset_x, offset_y = dc->offset_y;

    // Vulnerable offset correction
    corrected_x = offset_x + delta_x;
    corrected_y = offset_y + delta_y;

    // No range checking can lead to integer overflow
    if (corrected_x < 0 || corrected_y < 0)
        return; // Only handles negative values, not overflow

    apply_correction(frame, corrected_x, corrected_y); // Potential out-of-bounds access
}