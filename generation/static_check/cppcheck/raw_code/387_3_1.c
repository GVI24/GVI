#define AC3_HEADER_SIZE 10
#define AC3_MAX_STREAMS 8

struct ac3_stream {
    uint8_t *buffer;
    int buffer_size;
    // ...
};

static int ac3_read_header(AVFormatContext *s) {
    struct ac3_stream streams[AC3_MAX_STREAMS];
    int i;

    for (i = 0; i < AC3_MAX_STREAMS; i++) {
        streams[i].buffer = malloc(AC3_HEADER_SIZE);
        if (!streams[i].buffer) {
            // Vulnerability: Incomplete resource management
            return AVERROR(ENOMEM); // Previous buffers not freed
        }
        if (avio_read(s->pb, streams[i].buffer, AC3_HEADER_SIZE) != AC3_HEADER_SIZE) {
            // Read error occurred, but no cleanup of previously allocated buffers
            return AVERROR(EIO); // Previously allocated buffers not freed
        }
        // Process the read header
        // ...
    }
    // ... rest of the processing

    // Error path does not release allocated memory, causing potential memory leaks
    return 0;
}