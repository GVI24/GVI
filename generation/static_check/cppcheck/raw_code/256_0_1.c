#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 256

void string_concatenate(char *dest, const char *src) {
    // Vulnerable to buffer overflow if the size of src plus dest exceeds BUFFER_SIZE
    strcat(dest, src); // No bounds checking
}

int main() {
    char destBuffer[BUFFER_SIZE];
    const char *longString = "This is a very long string that could potentially cause an overflow in the buffer and lead to undefined behavior";

    // Initialize destBuffer with some content
    strcpy(destBuffer, "Initial content: ");
    // Concatenation without bounds checking
    string_concatenate(destBuffer, longString);

    return 0;
}