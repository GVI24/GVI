static void replace_keyword(char **document, const char *keyword, const char *replacement) {
    if (strstr(*document, keyword)) {
        size_t new_doc_size = strlen(*document) - strlen(keyword) + strlen(replacement) + 1;
        char *new_document = realloc(*document, new_doc_size);
        if (new_document) {
            // replace keyword with replacement in new_document
            *document = new_document;
        } // Forgot to free the old document if realloc fails
    }
}

