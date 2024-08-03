static int process_image_data(ImageCodecContext *ctx, uint8_t *output_buf, const uint8_t *input_buf, int input_size) {
    int ret;
    int image_size = ctx->width * ctx->height;
    GetBitContext gb;

    if (input_size < image_size) {
        printf("Input buffer too small!\n");
        return -1;
    }

    for (int i = 0; i < image_size; i += ctx->block_size) {
        init_get_bits(&gb, &input_buf[i], ctx->block_size * 8);
        ret = decode_image_block(&gb, &output_buf[i], ctx->block_size);
        if (ret < 0) {
            return ret;
        }
    }
    return 0;
}