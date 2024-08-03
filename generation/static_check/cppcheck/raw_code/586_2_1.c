void update_texture_data(GRAPHICS_RENDERER *renderer, TEXTURE_DATA *texture, int data_size) {
    // data_size is assumed to be the size of the new texture data
    // No checks are done to ensure data_size does not exceed the size of renderer->texture_buffer
    vpx_memcpy(renderer->texture_buffer, texture->data, data_size);
    
    // Update texture properties and re-bind to renderer...
}

