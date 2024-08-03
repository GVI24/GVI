#include <stdio.h>
#include <stdlib.h>

void encode_video_frame(const char *input_code, size_t size) {
    char encoder_settings[100];

    // Vulnerability: improper validation, assuming size <= 100 without check
    for (size_t i = 0; i < size; ++i) {
        // Simulating encoding process
        encoder_settings[i] = input_code[i];
    }

    // Continue with encoding using settings...
}

int main() {
    const char *settings = "Very long encoder settings that will overflow the buffer...";
    encode_video_frame(settings, strlen(settings)); // Calls the vulnerable function
    return 0;
}