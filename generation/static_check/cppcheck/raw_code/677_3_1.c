#include <stdio.h>
#include <stdlib.h>

#define MAX_CHUNKS 10
#define CHUNK_SIZE 64
#define TOTAL_SIZE (MAX_CHUNKS * CHUNK_SIZE)

typedef struct {
    char chunks[MAX_CHUNKS][CHUNK_SIZE];
    int chunk_count;
} ChunkContext;

int process_chunks(ChunkContext *ctx, const char *data_stream, int stream_length) {
    if (!ctx || !data_stream) {
        return -1;
    }

    int offset = 0;
    for (int i = 0; i < ctx->chunk_count; ++i) {
        if (offset + CHUNK_SIZE > stream_length) {
            // Vulnerable operation: offset may overflow leading to out-of-bounds read
            return -1; // Error should be returned before offset is misused
        }
        memcpy(ctx->chunks[i], data_stream + offset, CHUNK_SIZE); // Potential out-of-bounds read
        offset += CHUNK_SIZE; // Increment without bounds check
    }

    // Chunk processing...
    // ...

    return 0;
}

int main() {
    ChunkContext context;
    context.chunk_count = MAX_CHUNKS;
    char data_stream[TOTAL_SIZE + CHUNK_SIZE]; // Intentionally large stream size to create vulnerability

    process_chunks(&context, data_stream, sizeof(data_stream));

    return 0;
}