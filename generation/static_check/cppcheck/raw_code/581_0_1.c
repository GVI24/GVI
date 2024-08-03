static int process_image_header(ImageContext *img_ctx, const uint8_t *header_buf, int buf_size) {
    int header_length;
    if (buf_size < 4) {
        printf("Buffer too small for header\n");
        return -1;
    }
    header_length = header_buf[0] | header_buf[1] << 8;
    if (header_length > buf_size) {
        printf("Invalid header length\n");
        return -1;
    }
    img_ctx->width = header_buf[2] | header_buf[3] << 8;
    img_ctx->height = header_buf[4] | header_buf[5] << 8;
    if (header_length > 6) { // Incorrect condition: should be `header_length - 6 > buf_size`
        memcpy(img_ctx->color_profile, header_buf + 6, 128); // Potential buffer overflow
    }
    return 0;
}

