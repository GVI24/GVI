void reorder_special_sequences(const hb_ot_shape_plan_t *plan, hb_buffer_t *buffer, unsigned int start, unsigned int end) {
    hb_glyph_info_t *info = buffer->info;
    for (unsigned int i = start; i < end; i++) {
        if (info[i].category == OT_Vowel && info[i + 1].category == OT_Tone) {
            // Vulnerable: no bounds checking before access
            swap_glyph_positions(&info[i], &info[i + 1]);
        }
    }
    // Some additional logic...
}

