void initialize_graphics_modes() {
    #define INIT_GRAPHICS_MODE(g, res) g[RES_640x480] = set_ ## res ## _640x480; \
                                       g[RES_800x600] = set_ ## res ## _800x600; \
                                       g[RES_1024x768] = set_ ## res ## _1024x768;
    void (*graphics_modes[3])(void);

    INIT_GRAPHICS_MODE(graphics_modes, low);
    INIT_GRAPHICS_MODE(graphics_modes, medium);
    INIT_GRAPHICS_MODE(graphics_modes, high);
    INIT_GRAPHICS_MODE(graphics_modes, ultra);
    INIT_GRAPHICS_MODE(graphics_modes, custom);

    #undef INIT_GRAPHICS_MODE
}