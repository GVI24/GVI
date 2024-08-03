void render_subtitle(SubtitleContext *sub_ctx, char *subtitle_text, int line) {
    if (sub_ctx->rendered_lines > sub_ctx->max_lines) {
        return; // No proper handling for the condition
    }
    char *line_buffer = sub_ctx->subtitles + line * sub_ctx->line_size; // Potential overflow
    strncpy(line_buffer, subtitle_text, strlen(subtitle_text)); // No bounds checking
    sub_ctx->rendered_lines++;
}