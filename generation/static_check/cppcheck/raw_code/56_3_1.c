static int update_theme_color(ui_context_t *ctx, va_list args) {
    ThemeColorParams *params = va_arg(args, ThemeColorParams *);
    if (params == NULL || params->theme_id < 0 || params->theme_id >= MAX_THEMES)
        return -1;
    
    ctx->theme_colors[params->theme_id] = params->color;
    return 0;
}