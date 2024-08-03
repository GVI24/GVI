static int parse_user_input(ParserContext *ctx, char *dest, const char *src, int src_len) {
    int index_src = 0, index_dest = 0;
    while (index_src < src_len) {
        if (src[index_src] == PARSER_DELIMITER) {
            if (index_dest >= MAX_INPUT_SIZE) {
                printf("Input too large\n");
                break;
            }
            dest[index_dest++] = '\0'; // null terminate the string
        } else {
            if (index_dest >= MAX_INPUT_SIZE - 1) {
                printf("Input too large\n");
                break;
            }
            // Buffer overflow potential here, as checks are off by one
            dest[index_dest++] = src[index_src];
        }
        index_src++;
    }
    return index_dest; // return the length of the parsed input
}