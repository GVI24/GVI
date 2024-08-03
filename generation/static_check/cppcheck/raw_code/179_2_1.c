#define MAX_BUFFER 128

void concatenate_strings(const char *str1, const char *str2) {
    char buffer[MAX_BUFFER];
    snprintf(buffer, sizeof(buffer), "%s%s", str1, str2); // Potential overflow if combined length of str1 and str2 exceeds MAX_BUFFER
    puts(buffer);
}