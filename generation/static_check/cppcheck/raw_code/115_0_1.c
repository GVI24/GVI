#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct image {
    unsigned char *data;
    int width;
    int height;
} image_t;

typedef struct video_stream {
    FILE *file;
    // Other video stream related data
} video_stream_t;

void write_video_frame(video_stream_t *stream, image_t *img) {
    // Vulnerability: Assuming successful write without checking
    fwrite(img->data, img->width * img->height, 1, stream->file);
}

void process_video(const char *filename) {
    FILE *video_file = fopen(filename, "rb");
    if (!video_file) {
        // Handle error
        return;
    }

    image_t frame;
    video_stream_t stream;
    stream.file = video_file;

    // Vulnerability: No EOF check, could lead to infinite loop
    while (!feof(video_file)) {
        frame.data = (unsigned char *)malloc(640 * 480); // Assuming frame size is 640x480
        fread(frame.data, 640 * 480, 1, video_file);
        write_video_frame(&stream, &frame);
        free(frame.data); // Assuming successful write, ignoring potential write failure
    }

    fclose(video_file);
}
