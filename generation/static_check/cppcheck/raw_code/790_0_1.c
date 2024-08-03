char *xmlGetElementContent(const xmlChar *filename) {
    FILE *file = fopen((const char *)filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return NULL;
    }
    char *content = malloc(1024); // fixed-size buffer
    if (content == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }
    // UNSAFE: Fgets does not ensure that content does not exceed buffer size
    fgets(content, 2048, file); // potential buffer overflow
    fclose(file);
    return content;
}

