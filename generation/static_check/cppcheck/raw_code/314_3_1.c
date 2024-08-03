#include <string.h>
#include <stdlib.h>

char *build_message(const char *text1, const char *text2) {
    size_t text1_len = strlen(text1);
    size_t text2_len = strlen(text2);
    // Incorrect length: needs space for text1, text2, and null terminator.
    size_t message_len = text1_len + text2_len; // Off by one error; no space for '\0'
    char *message = (char *)malloc(message_len); // Could result in buffer overflow
    if (message == NULL) {
        // Handle error
        return NULL;
    }
    // Potential buffer overflow due to incorrect message_len.
    memcpy(message, text1, text1_len);
    memcpy(message + text1_len, text2, text2_len);
    // Missing null terminator can cause undefined behavior.
    return message;
}