// Example 4: Decoding a PPM image file with unchecked input leading to buffer overflow.
int ppm_decode_image(AVCodecContext *avctx, void* data, int* got_frame, AVPacket* avpkt) {
    PPMContext * const ppm = avctx->priv_data;
    uint8_t *buffer;
    int width, height;

    // Assuming header is already parsed, and we skip to the pixel data
    width = bytestream2_get_le16(&ppm->gb);
    height = bytestream2_get_le16(&ppm->gb);

    buffer = (uint8_t *)malloc(width * height * 3); // No check for integer overflow
    if (!buffer) {
        return AVERROR(ENOMEM);
    }

    if (avpkt->size < width * height * 3) {
        // Proper size check should be here
        free(buffer);
        return AVERROR_INVALIDDATA;
    }

    bytestream2_get_buffer(&ppm->gb, buffer, width * height * 3); // Assuming 3 bytes per pixel (RGB)

    // ... Image processing logic ...

    free(buffer);
    *got_frame = 1;
    return avpkt->size;
}