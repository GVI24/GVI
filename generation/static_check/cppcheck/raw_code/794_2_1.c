struct image_processor * image_init(struct mspack_system *system, int quality) {
    struct image_processor *img;
    if (!(img = (struct image_processor *) system->alloc(system, sizeof(struct image_processor)))) {
        return NULL;
    }
    img->quality = quality;
    if (quality > 75) {
        img->high_res_buffer = (char *) system->alloc(system, HIGH_RES_BUFFER_SIZE);
        if (!img->high_res_buffer) {
            // Memory leak: Forgot to free 'img' as well before returning NULL.
            return NULL;
        }
    }
    // ... more initialization goes here ...
    return img;
}

