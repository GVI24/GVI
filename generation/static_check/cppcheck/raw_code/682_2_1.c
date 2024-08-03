#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} VideoFrame;

void initialize_frame(VideoFrame *frame, int width, int height) {
    // Vulnerability: No NULL check on frame pointer
    frame->data = (unsigned char *)malloc(width * height);
    if (frame->data == NULL) {
        printf("Unable to allocate memory for the frame data\n");
    }
    frame->width = width;
    frame->height = height;
}

int main() {
    VideoFrame *myFrame = NULL;
    initialize_frame(myFrame, 640, 480); // Calls the vulnerable function with a NULL pointer
    free(myFrame->data); // Would cause a crash
    free(myFrame);
    return 0;
}