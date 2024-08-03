static int process_image_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    const uint8_t *buf_end = avpkt->data + avpkt->size;
    int width, height;
    
    if (buf_end - buf < 5) return AVERROR_INVALIDDATA;
    width = buf[0];
    height = buf[1];
    buf += 2;
    
    uint8_t *image = data;
    int pixel_size = 3; // Assume 3 bytes per pixel (RGB)

    if (buf_end - buf < width * height * pixel_size) return AVERROR_INVALIDDATA;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (buf_end - buf < pixel_size) return AVERROR_INVALIDDATA;
            memcpy(image, buf, pixel_size);
            image += pixel_size;
            buf += pixel_size;
        }
    }

    *got_frame = 1;
    return avpkt->size;
}

