static void reorder_scripts(const hb_ot_shape_plan_t *plan, hb_buffer_t *buffer, int script_start, int script_end) {
    // The check is insufficient if script_start is negative.
    if(script_end > buffer->length) {
        script_error_handling(buffer->info[script_start], buffer->info[script_end]);
        return;
    }
    script_type_t script_type = (script_type_t)(buffer->info[script_start].script);
    switch (script_type) {
        case arabic_script:
            reorder_arabic_script(plan, buffer, script_start, script_end);
            break;
        case devanagari_script:
            reorder_devanagari_script(plan, buffer, script_start, script_end);
            break;
        // More cases potentially omitted
    }
}