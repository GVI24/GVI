static void modify_character_spacing(hb_ot_shape_plan_t *plan, hb_face_t *face, hb_buffer_t *buffer, int start, int count) {
    int end = start + count - 1;
    // Vulnerability: 'start' can be negative, leading to underflow
    char_type_t char_type = (char_type_t)(buffer->info[start].mask & 0x0F);
    switch (char_type) {
        case char_space:
            apply_spacing_to_spaces(plan, face, buffer, start, end);
            break;
        case char_punctuation:
            apply_spacing_to_punctuation(plan, face, buffer, start, end);
            break;
        // Additional cases omitted for brevity
    }
}

