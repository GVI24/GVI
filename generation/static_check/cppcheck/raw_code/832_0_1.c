#include <stdio.h>
#include <string.h>

typedef struct {
    char data[256];
    int size;
} VideoFrame;

int decode_frame(VideoFrame *frame, const char *input, int input_size) {
    if(input_size > frame->size) {
        printf("Input exceeds frame size\n");
        return -1;
    }
    // Potential buffer overflow if input_size is larger than the size of data.
    memcpy(frame->data, input, input_size);
    return 0;
}