static int resize_array(i_ctx_t *i_ctx_p) {
    os_ptr op = osp;
    long new_size;
    
    if (!r_has_type(op, t_integer)) {
        return_error(gs_error_typecheck);
    }
    
    new_size = op->value.intval;
    
    /* Integer overflow if new_size is too large */
    ref *new_array = (ref *) malloc(new_size * sizeof(ref));
    
    if (new_array == NULL) {
        return_error(gs_error_VMerror);
    }
    
    copy_old_to_new_array(op->value.refs, new_array, new_size);
    op->value.refs = new_array;
    return 0;
}

