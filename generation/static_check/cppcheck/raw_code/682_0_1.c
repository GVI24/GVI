#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_video_frame(char *frame_data, int data_length) {
    char frame_buffer[256];
    if (data_length > 256) {
        printf("Error: Data length too large\n");
        return;
    }
    // Vulnerability: buffer overflow if data_length > 256
    memcpy(frame_buffer, frame_data, data_length);
    // Process frame...
}

int main() {
    char *data = "This is some frame data that is way too long and will cause a buffer overflow";
    process_video_frame(data, strlen(data)); // Calls the vulnerable function
    return 0;
}