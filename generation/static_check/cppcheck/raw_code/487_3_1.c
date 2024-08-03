static int compile_block(i_ctx_t *i_ctx_p, scanner_state *pstate) {
    os_ptr op = osp;
    int code;
    ref block;
    
    pop(1);
block_compile:
    code = gs_compile_block(i_ctx_p, &block, pstate);
    if (code < 0) {
        gs_compile_error_object(i_ctx_p, pstate, &i_ctx_p->error_object);
    } else {
        op -= 2; // Potential underflow
        ref_assign(op, &block);
        make_integer(op + 1, code);
    }
    
    if (code <= 0) {
        ifree_object(pstate, "compile_block");
    }
    return code;
}