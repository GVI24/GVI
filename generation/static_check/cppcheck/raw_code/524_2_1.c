typedef struct {
    char *buffer;
    int index;
} StreamState;

void read_stream(StreamState *stream, const char *data, int size) {
    if (size < 100) {
        // Vulnerability: assumes size is at least 100 without checking
        memcpy(stream->buffer + stream->index, data, 100);
        stream->index += 100;
    }
    // Continue processing stream
}

// ---------------------------------------------------------------
