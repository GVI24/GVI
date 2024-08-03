static void _freeLocaleList(char **locales, int32_t count, UBool shouldFree) {
    int32_t i;
    if (locales == NULL || count < 0) {
        return;
    }
    if (shouldFree) {
        for (i = 0; i < count; i++) {
            uprv_free(locales[i]);
        }
        uprv_free(locales); // locales is freed here
    }
    // ... Perform other operations ...
    
    // Double free: locales and/or its elements may be freed again
    for (i = 0; i < count; i++) {
        uprv_free(locales[i]);
    }
    uprv_free(locales);
}