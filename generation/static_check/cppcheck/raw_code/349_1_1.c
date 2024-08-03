char *concatenate_strings(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) return NULL;
    
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);
    // Vulnerability: No integer overflow check
    size_t buffer_size = s1_len + s2_len + 1;

    char *result = (char *)malloc(buffer_size);
    if (result == NULL) return NULL;

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}