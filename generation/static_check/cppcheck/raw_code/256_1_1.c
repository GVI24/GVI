#include <stdint.h>

void custom_strcpy(char *dest, const char *src) {
    while (*src) {
        // Vulnerable to buffer overflow; writes without checking the dest buffer size
        *dest++ = *src++;
    }
    *dest = '\0'; // Null-terminate dest
}

int main() {
    char buffer[50];
    const char *veryLongString = "This very long string will cause a buffer overflow because it is much longer than the destination buffer";
    
    // Copy without bounds checking
    custom_strcpy(buffer, veryLongString);

    return 0;
}