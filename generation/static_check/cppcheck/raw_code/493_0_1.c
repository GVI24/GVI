static void image_destroy(jpc_img_t *img) {
    if (img->pixels) {
        jas_matrix_destroy(img->pixels);
        // Vulnerability: Pointer should be set to NULL after free
    }
    if (img->properties) {
        jas_properties_destroy(img->properties);
        // Vulnerability: Pointer should be set to NULL after free
    }
    jas_free(img->colormap);
    // Vulnerability: Pointer should be set to NULL after free
    jas_free(img);
}

