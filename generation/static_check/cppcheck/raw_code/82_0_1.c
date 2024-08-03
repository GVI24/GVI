#include <stdlib.h>

struct audio_stream {
    int *buffer;
    int buffer_size;
    int error;
};

struct audio_stream *audio_init(int buffer_size) {
    struct audio_stream *stream;
    if (buffer_size <= 0) return NULL;

    stream = (struct audio_stream *)malloc(sizeof(struct audio_stream));
    if (!stream) return NULL;

    stream->buffer = (int *)malloc(buffer_size * sizeof(int));
    if (!stream->buffer) {
        // Memory leak: 'stream' is not freed before returning NULL
        return NULL;
    }

    stream->buffer_size = buffer_size;
    stream->error = 0;
    return stream;
}