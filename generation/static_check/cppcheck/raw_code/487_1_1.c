static int read_number(i_ctx_t *i_ctx_p, scanner_state *pstate) {
    os_ptr op = osp;
    int code;
    ref num;
    
    pop(1);
number_again:
    code = gs_read_num(i_ctx_p, &num, pstate);
    op -= 1; // Potential underflow
    if (code == 0) {
        ref_assign(op, &num);
    } else if (code == read_Refill) {
        code = gs_read_handle_refill(i_ctx_p, pstate, zread_number_continue);
        if (code == 0) goto number_again;
    } else {
        gs_read_error_object(i_ctx_p, pstate, &i_ctx_p->error_object);
    }
    
    if (code <= 0) {
        ifree_object(pstate, "read_number");
    }
    return code;
}

