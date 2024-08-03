static int execute_stream(i_ctx_t *i_ctx_p, scanner_state *pstate) {
    os_ptr op = osp;
    int code;
    ref cmd;
    
    pop(1);
stream_exec:
    code = gs_exec_stream(i_ctx_p, &cmd, pstate);
    op = osp;
    if (code == exec_Ready) {
        ref_assign(op, &cmd);
        op += 2; // Potential overflow
        make_null(op);
    } else if (code == exec_Refill) {
        code = gs_exec_handle_refill(i_ctx_p, pstate, zexecute_stream_continue);
        if (code == 0) goto stream_exec;
    }
    
    if (code <= 0) {
        ifree_object(pstate, "execute_stream");
    }
    return code;
}

