static int process_image_data(ImageContext *img_ctx, uint8_t *dest, AVPacket *pkt) {
    int width, height, ret;
    uint8_t *src = pkt->data;
    width = bytestream_get_le16(&src);
    height = bytestream_get_le16(&src);

    if (pkt->size < width * height + 4) {
        fprintf(stderr, "Packet too small for resolution\n");
        return -1;
    }

    if (src + width * height > pkt->data + pkt->size) {
        fprintf(stderr, "Image data exceeds packet size\n");
        return -1;
    }

    memcpy(dest, src, width * height); // Potential overflow

    return 0;
}