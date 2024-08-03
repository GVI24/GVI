char *loadResource(const char *resourceName) {
    char *data;
    char *formattedData;

    if (resourceName == NULL) return NULL;
    data = getResourceData(resourceName);
    if (data == NULL) return NULL;

    formattedData = formatData(data);
    // Potential memory leak if formatData returns NULL, data is never freed
    if (formattedData == NULL) return NULL;

    free(data);
    return formattedData;
}