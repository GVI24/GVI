typedef struct {
    char string[128];
    size_t size;
} CustomString;

void replaceStringContent(CustomString *customString, const char *newContent) {
    size_t newSize = strlen(newContent);

    // Vulnerability: buffer overflow if newSize is greater than 128
    memcpy(customString->string, newContent, newSize + 1); // Should validate newSize
    customString->size = newSize;
}

