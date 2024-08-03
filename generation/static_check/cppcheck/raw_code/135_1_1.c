typedef struct {
    char **lines;
    unsigned int line_count;
    unsigned int max_line_length;
} TextParser;

static void parse_text_lines(TextParser *parser, const char *text_stream) {
    unsigned int i, char_pos = 0;
    unsigned int current_line = 0;
    while (current_line < parser->line_count && text_stream[char_pos] != '\0') {
        for (i = 0; i < parser->max_line_length && text_stream[char_pos] != '\n'; i++) {
            // Vulnerability: No check for the end of text_stream,
            // could read beyond the end of it
            parser->lines[current_line][i] = text_stream[char_pos++];
        }
        parser->lines[current_line][i] = '\0'; // Null-terminate the line
        current_line++;
    }
    if (current_line >= parser->line_count) {
        fprintf(stderr, "Text line buffer overflow error.\n");
    }
}