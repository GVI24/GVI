static int render_subtitle(SubtitleContext *sub_ctx, SubtitlePacket *sub_packet) {
    if (!sub_ctx || !sub_packet) {
        fprintf(stderr, "Invalid context or packet\n");
        return -1;
    }

    char *rendered_text = malloc(sub_packet->text_length + 1); // No check for zero length
    if (!rendered_text) {
        fprintf(stderr, "Memory allocation for subtitle text failed\n");
        return -1;
    }

    strcpy(rendered_text, sub_packet->text); // Potential null pointer dereference if text is NULL
    int result = display_subtitle(sub_ctx, rendered_text);

    free(rendered_text);
    return result;
}