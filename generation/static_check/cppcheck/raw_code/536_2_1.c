static int create_image_buffer(ImageContext *ictx, ImageBuffer *ibuffer) {
    int pixel_count = ictx->width * ictx->height;
    int ret;

    ibuffer->rgb_pixels = av_mallocz(pixel_count * 3); // Assuming RGB pixels
    if (!ibuffer->rgb_pixels) return AVERROR(ENOMEM);

    ibuffer->alpha_channel = av_mallocz(pixel_count);
    if (!ibuffer->alpha_channel) { /* Missing deallocation of ibuffer->rgb_pixels before returning */
        return AVERROR(ENOMEM);
    }

    ret = ff_process_image(ictx, ibuffer);
    if (ret < 0) { /* Missing deallocation of ibuffer->rgb_pixels and ibuffer->alpha_channel before returning */
        return ret;
    }

    return 0;
}

