texture_t *texture_create_from_data(image_data_t *img_data) {
    if (!img_data || !img_data->length) {
        return NULL; // Should return a default empty texture
    }

    texture_t *texture;
    texture_data_t *data = process_image_data(img_data); // Memory allocated here

    if (!data) {
        return NULL;
    }

    texture = create_texture_object(data); // Fails to check if texture creation succeeded
    // Missing cleanup for 'data' if texture creation fails

    return texture;
}

