void configure_render_modes() {
    #define SET_RENDER_MODE(m, type) m[MODE_2D] = render_ ## type ## _2d; \
                                      m[MODE_3D] = render_ ## type ## _3d;
    void (*render_modes[2])(void);

    SET_RENDER_MODE(render_modes, solid);
    SET_RENDER_MODE(render_modes, wireframe);
    SET_RENDER_MODE(render_modes, shaded);
    SET_RENDER_MODE(render_modes, textured);
    SET_RENDER_MODE(render_modes, pointcloud);

    #undef SET_RENDER_MODE
}