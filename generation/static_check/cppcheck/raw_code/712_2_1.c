typedef struct {
    char *content;
    size_t size;
} DynamicString;

DynamicString* loadFileContent(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    DynamicString *dString = (DynamicString *)malloc(sizeof(DynamicString));
    if (dString == NULL) {
        // Missing: fclose(file);
        return NULL;
    }

    dString->content = (char *)malloc(fsize + 1);
    if (dString->content == NULL) {
        // Missing: fclose(file); free(dString);
        return NULL;
    }

    fread(dString->content, 1, fsize, file);
    fclose(file);
    dString->content[fsize] = 0;
    dString->size = fsize;

    return dString;
}
