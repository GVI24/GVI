typedef struct {
    char *name;
    char *data;
    int dataSize;
} Resource;

Resource *CopyResource(Resource *res) {
    Resource *copy = (Resource *)malloc(sizeof(Resource));
    // Vulnerability: No NULL check after malloc
    copy->name = strdup(res->name); // Vulnerability: No NULL check after strdup
    copy->dataSize = res->dataSize;
    copy->data = (char *)malloc(copy->dataSize);
    // Vulnerability: No NULL check after malloc
    memcpy(copy->data, res->data, copy->dataSize); // Vulnerability: No boundary check
    return copy;
}