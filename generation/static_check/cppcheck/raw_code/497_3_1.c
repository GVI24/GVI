static int render_graphics_tile(void *graphics_context, void *tile_info) {
    GraphicsContext *gctx = (GraphicsContext *)graphics_context;
    TileData *tile = (TileData *)tile_info;
    int pixel_x, pixel_y;
    for (pixel_y = tile->start_y; pixel_y < tile->end_y; pixel_y++) {
        for (pixel_x = tile->start_x; pixel_x < tile->end_x; pixel_x++) {
            render_pixel(gctx->buffer, tile, pixel_x, pixel_y);
        }
    }
    return gctx->is_frame_rendered;
}