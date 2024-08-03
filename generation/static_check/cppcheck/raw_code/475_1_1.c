font_face * get_font_face(fz_context * ctx, font_library * lib, const char * font_name) {
    font_face * font;
    font = find_font_face(ctx, lib, font_name);
    if (font != NULL)
        return font; // Potential use-after-free if font is released elsewhere.

    font = fz_malloc(ctx, sizeof(font_face));
    font->ref_count = 1;
    font->name = strdup(font_name);
    add_font_face_to_library(ctx, lib, font);
    
    return font;
}