void render_text(char *text, char *buffer, size_t buffer_size) {
    size_t text_length = strlen(text);
    // Vulnerable: No check to ensure text_length + 1 <= buffer_size
    memcpy(buffer, text, text_length + 1);
}

