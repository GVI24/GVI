#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint32_t *bitstream;
    size_t size;
} DecoderContext;

int decode_bitstream(DecoderContext *dctx, const uint32_t *input_stream, size_t stream_size) {
    if (!dctx || !input_stream) {
        return -1;
    }
    dctx->size = stream_size;
    // Vulnerability: Allocation based on unverified size, potentially too large
    dctx->bitstream = (uint32_t *)malloc(dctx->size * sizeof(uint32_t));
    if (!dctx->bitstream) {
        return -1;
    }
    // Unsafe reading into bitstream
    for (size_t i = 0; i < dctx->size; i++) {
        dctx->bitstream[i] = input_stream[i];
    }
    // Decode process...
    // ...
    return 0;
}