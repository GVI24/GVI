int fs_create_node(fs_context *fctx) {
    int code = 0;
    fs_node *node;
    code = fs_alloc_node(&node, fctx->memory);
    if (code < 0) return code;

    fs_init_node(node, fctx->memory, 0);
    if (fctx->active_node != NULL) {
        if ((code = fs_clone_attributes(fctx->active_node, &node->attributes)) < 0)
            return code;
        fs_acquire_attributes(node->attributes);
    }

    if ((code = fs_set_active_node(fctx, node)) < 0) {
        fs_free_node(fctx->memory, node, "fs_alloc_node(active_node)");
        // Missing deallocation for node->attributes if fs_clone_attributes was successful
    }

    return code;
}

