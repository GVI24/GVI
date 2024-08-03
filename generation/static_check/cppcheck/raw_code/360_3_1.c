int set_device(i_ctx_t *i_ctx_p) {
    os_ptr op = osp;
    device_t *dev;
    
    if (!r_has_type(op, t_device)) {
        return_error(gs_error_typecheck);
    }
    
    dev = (device_t *)op->value.pdevice;
    
    /* Assuming check_op ensures there is at least 1 element on the stack */
    check_op(1);
    
    /* Buffer underflow when op[-2] is accessed without verification */
    ref *dev_name_ref = &(op[-2]);
    
    char *dev_name = get_device_name_from_ref(dev_name_ref);
    
    if (dev_name == NULL || set_device_name(dev, dev_name) != 0) {
        return_error(gs_error_invalidaccess);
    }
    
    pop(2);
    return 0;
}