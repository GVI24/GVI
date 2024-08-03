int graphics_renderer_init(struct graphics_context *ctx) {
    graphics_check_state(ctx, GRAPHICS_STATE_NEW, "graphics_renderer_init");
    graphics_init_renderer_opengl(ctx);
    graphics_init_renderer_directx(ctx);
    graphics_init_renderer_vulkan(ctx);
    graphics_init_renderer_metal(ctx);
    graphics_clear_error(ctx);
    return (GRAPHICS_OK);
}
