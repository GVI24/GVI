static int load_image_data(ImageContext *img_ctx, const uint8_t *buffer, int buffer_len) {
    int width, height;
    const uint8_t *data_ptr = buffer;

    // Expecting a specific format without validation can lead to out-of-bounds reads.
    width = *(int *)data_ptr;
    data_ptr += sizeof(int);
    height = *(int *)data_ptr;
    data_ptr += sizeof(int);

    img_ctx->width = width;
    img_ctx->height = height;

    // Allocating based on the values extracted without checking for integer overflows.
    img_ctx->data = (uint8_t *)malloc(width * height * sizeof(uint32_t));
    if (!img_ctx->data) {
        return -1;
    }

    // Potentially copying more data than the buffer contains.
    memcpy(img_ctx->data, data_ptr, width * height * sizeof(uint32_t));

    return 0;
}