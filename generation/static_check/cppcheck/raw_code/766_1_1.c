// Example 2: Decoding a simple raw video frame without validating dimensions.
int rawvideo_decode_frame(AVCodecContext *avctx, void* data, int* got_frame, AVPacket* avpkt) {
    RawVideoContext * const context = avctx->priv_data;
    uint8_t *dest;
    unsigned int frame_size, width, height;

    width = bytestream2_get_le16(&context->gb);
    height = bytestream2_get_le16(&context->gb);
    
    // Assuming pixel format is always 3 bytes per pixel
    frame_size = width * height * 3; 
    dest = malloc(frame_size); // Potential integer overflow and no boundary check with avpkt->size
    if (!dest) {
        return AVERROR(ENOMEM);
    }

    // No check for the avpkt->size against the calculated frame size
    bytestream2_get_buffer(&context->gb, dest, frame_size);

    // ... Image processing logic ...

    free(dest);
    *got_frame = 1;
    return avpkt->size;
}