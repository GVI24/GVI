#include <stdio.h>

typedef struct {
    int frame_count;
    float timestamps[100];
} VideoStream;

int add_timestamp(VideoStream *stream, float timestamp, int index) {
    // No bounds checking for index, can lead to out of bounds write.
    if(stream->frame_count >= 100) {
        printf("Maximum frame count reached\n");
        return -1;
    }
    stream->timestamps[index] = timestamp; // Vulnerable if index is out of bounds.
    stream->frame_count++;
    return 0;
}