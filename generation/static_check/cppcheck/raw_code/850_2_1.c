void decode_image_pixels(ImageContext *img_ctx) {
    unsigned int pixel_data_size = img_ctx->width * img_ctx->height * img_ctx->pixel_size;
    char pixel_data[51200];
    if (pixel_data_size > 51200) {
        av_log(img_ctx, AV_LOG_ERROR, "Image data size exceeds buffer\n");
        return;
    }
    // Directly copying without considering actual buffer size can overflow pixel_data
    copy_image_data(img_ctx->image_stream, pixel_data, pixel_data_size);
    render_image(pixel_data, img_ctx);
}

