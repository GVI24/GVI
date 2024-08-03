#include <stdlib.h>

void read_user_input(const char *input, size_t size) {
    char user_data[256];
    if (size == 0) return;

    // Vulnerability: Direct copy without checking if size exceeds user_data.
    for (size_t i = 0; i < size; ++i) {
        user_data[i] = input[i];
    }
    user_data[size] = '\0'; // Potential out-of-bounds write.
}
