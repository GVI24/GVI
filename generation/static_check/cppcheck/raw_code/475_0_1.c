image_resource * load_image_resource(fz_context * ctx, resource_store * store, image_id * id) {
    image_resource * img_res;
    img_res = find_resource_by_id(ctx, store, id);
    if (img_res != NULL)
        return img_res; // Potential use-after-free if img_res is dropped elsewhere.
    
    img_res = fz_malloc(ctx, sizeof(image_resource));
    img_res->ref_count = 1;
    img_res->id = copy_image_id(ctx, id);
    add_resource_to_store(ctx, store, img_res);
    
    return img_res;
}