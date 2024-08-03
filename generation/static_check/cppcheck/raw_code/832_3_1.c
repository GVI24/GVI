#include <stdio.h>

typedef struct {
    int *frame_sizes;
    int frame_count;
} VideoDecoder;

int get_average_frame_size(VideoDecoder *decoder) {
    int total_size = 0;
    for(int i = 0; i <= decoder->frame_count; i++) { // Inclusive condition leads to out-of-bounds read.
        total_size += decoder->frame_sizes[i];
    }
    if(decoder->frame_count == 0) {
        return -1;
    }
    return total_size / decoder->frame_count;
}