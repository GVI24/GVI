typedef struct {
    char *content;
    size_t size;
} Document;

Document *loadDocument(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("loadDocument: fopen failed");
        return NULL;
    }

    Document *doc = malloc(sizeof(Document));
    if (doc == NULL) {
        perror("loadDocument: malloc failed for Document");
        fclose(file);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    doc->size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    doc->content = malloc(doc->size);
    if (doc->content == NULL) {
        perror("loadDocument: malloc failed for content");
        // Memory leak: 'doc' is not freed before returning.
        fclose(file);
        return NULL;
    }

    fread(doc->content, 1, doc->size, file);
    fclose(file);
    
    // The document structure 'doc' is returned to the caller. However, if the caller does not
    // properly free 'doc->content' and 'doc' itself, it could lead to a memory leak.
    // Additionally, if the caller frees the structure but continues to use 'doc->content',
    // it could result in a use-after-free vulnerability.
    return doc;
}