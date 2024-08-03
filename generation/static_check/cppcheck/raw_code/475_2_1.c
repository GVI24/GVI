cached_texture * load_texture(cache_manager * cache, texture_id id) {
    cached_texture * tex;
    tex = cache_lookup(cache, id);
    if (tex != NULL)
        return tex; // Potential use-after-free if tex is removed from cache.

    tex = malloc(sizeof(cached_texture));
    tex->ref_count = 1;
    tex->id = id;
    tex->data = load_texture_data(id);
    cache_insert(cache, id, tex);
    
    return tex;
}