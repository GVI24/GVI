#include <stdint.h>

#define BUFFER_LIMIT 128

void process_data(const char *input) {
    char buffer[BUFFER_LIMIT];
    int i = 0;

    // Vulnerable to buffer overflow since there is no check for the length of input
    while (input[i] != '\0') {
        buffer[i] = input[i];
        i++;
    }
    buffer[i] = '\0';
}

int main() {
    const char *data = "This input data is too long and exceeds the buffer limit, causing a buffer overflow";
    
    // Process data without bounds checking
    process_data(data);

    return 0;
}