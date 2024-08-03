#define BUFFER_SIZE 128
typedef struct {
    unsigned char buffer[BUFFER_SIZE];
    size_t index;
} data_stream;

int read_stream(data_stream *stream, unsigned char *dest, size_t length) {
    if (stream->index + length > BUFFER_SIZE) {
        return -1; // Insufficient buffer space check
    }
    memcpy(dest, &stream->buffer[stream->index], length); // Vulnerability: read before the check
    stream->index += length;
    return 0;
}

