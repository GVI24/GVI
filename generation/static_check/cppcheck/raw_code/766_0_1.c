// Example 1: Decoding a BMP file with potential buffer overflow.
int bmp_decode_image(AVCodecContext *avctx, void* data, int* got_frame, AVPacket* avpkt) {
    BMPContext * const bmp = avctx->priv_data;
    unsigned int width, height, bit_count;
    uint8_t * buffer;

    bytestream2_skip(&bmp->gb, 18); // Skip to width/height info
    width = bytestream2_get_le32(&bmp->gb);
    height = bytestream2_get_le32(&bmp->gb);
    bytestream2_skip(&bmp->gb, 2); // Skip planes
    bit_count = bytestream2_get_le16(&bmp->gb);

    if (bit_count != 24 && bit_count != 32) {
        av_log(avctx, AV_LOG_ERROR, "Unsupported bit count: %u\n", bit_count);
        return AVERROR_PATCHWELCOME;
    }

    buffer = malloc(width * height * (bit_count / 8)); // Potential integer overflow
    if (!buffer) {
        return AVERROR(ENOMEM);
    }

    for (unsigned int y = 0; y < height; ++y) {
        // No boundary check on the size of the incoming data
        bytestream2_get_buffer(&bmp->gb, buffer + y * width * (bit_count / 8), width * (bit_count / 8));
    }

    // ... Image processing logic ...

    free(buffer);
    *got_frame = 1;
    return avpkt->size;
}