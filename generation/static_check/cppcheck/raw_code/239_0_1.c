static void apply_text_transformations(const hb_ot_shape_plan_t *plan, hb_buffer_t *buffer, unsigned int index) {
    if (index < buffer->length && buffer->info[index].is_uppercase()) {
        text_transformation_t transformation = (text_transformation_t)(buffer->info[index].codepoint);
        switch (transformation) {
            case uppercase_transform:
                uppercase_transformation(plan, buffer, index);
                break;
            case lowercase_transform:
                lowercase_transformation(plan, buffer, index);
                break;
            // More cases potentially omitted
        }
    } else {
        // Potential underflow if index is out of range.
        transformation_error_handling(buffer->info[index]);
    }
}

