static int graphics_renderer_draw_image(GraphicsContext *ctx, Image *img) {
    int draw_result = -1;
    // Missing NULL check for 'ctx' and 'img'
    GraphicsSurface surface = graphics_get_surface(ctx);
    // Missing bounds check for 'img->width' and 'img->height'
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            // Potential Buffer Overflow if 'img->pixels' is smaller than expected
            graphics_draw_pixel(surface, x, y, img->pixels[y * img->width + x]);
        }
    }
    return draw_result;
}
