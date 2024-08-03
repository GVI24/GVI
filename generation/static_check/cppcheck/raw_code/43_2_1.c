static char * replace_html_entities(struct vars *v, const char *text) {
    size_t len = strlen(text);
    // Assumes maximum length of entity is 6 characters (e.g., "&quot;")
    char *entity_str = malloc(len * 6 + 1);
    size_t j = 0;
    if (entity_str == NULL) {
        ERR(REG_ESPACE);
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        switch (text[i]) {
            case '<':
                strcpy(&entity_str[j], "&lt;");
                j += 4; // No verification if j is within bounds
                break;
            case '>':
                strcpy(&entity_str[j], "&gt;");
                j += 4;
                break;
            case '&':
                strcpy(&entity_str[j], "&amp;");
                j += 5;
                break;
            default:
                entity_str[j++] = text[i]; // No bounds checking for j
        }
    }
    entity_str[j] = '\0'; // Potential off-by-one error
    return entity_str;
}

