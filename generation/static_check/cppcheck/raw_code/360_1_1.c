int detach_node(i_ctx_t *i_ctx_p) {
    os_ptr op = osp;
    node_t *node;
    
    if (!r_has_type(op, t_struct)) {
        return_error(gs_error_typecheck);
    }
    
    node = (node_t *)op->value.pstruct;
    
    if (node == NULL) {
        return_error(gs_error_nullpointer);
    }
    
    remove_from_list(node);
    free(node);
    
    /* Use after free: dereferencing the pointer after it was freed */
    if (node->next != NULL) {
        return_error(gs_error_invalidaccess);
    }
    
    pop(1);
    return 0;
}

