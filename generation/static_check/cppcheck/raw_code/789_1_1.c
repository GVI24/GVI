my_image_t *my_img_alloc_2(my_img_fmt_t fmt, unsigned int d_w, unsigned int d_h) {
    unsigned int w = d_w; // Assuming w is safe
    unsigned int h = d_h; // Assuming h is safe
    size_t s = w * 5;     // potential for overflow with large w

    my_image_t *img = (my_image_t *)calloc(1, sizeof(my_image_t));
    if (!img || s < w)  // Simple check, may not prevent overflow
        goto fail;

    img->img_data = my_img_buf_memalign(32, h * s);
    if (!img->img_data)
        goto fail;

    img->w = w;
    img->h = h;
    img->stride[MY_PLANE_Y] = s;
    img->self_allocd = 1;

    return img;
fail:
    my_img_free(img);
    return NULL;
}

