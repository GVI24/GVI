static int parse_expression(i_ctx_t *i_ctx_p, scanner_state *pstate) {
    os_ptr op = osp;
    int code;
    ref expr;
    
    pop(1);
parse_again:
    code = gs_parse_expr(i_ctx_p, &expr, pstate);
    switch (code) {
        default:
            if (code > 0) code = gs_note_error(gs_error_syntaxerror);
            gs_parser_error_object(i_ctx_p, pstate, &i_ctx_p->error_object);
            break;
        case parse_BOS:
            code = 0;
        case 0:
            op += 3; // Potential overflow
            ref_assign(op, &expr);
            make_true(op + 1);
            make_false(op + 2);
            break;
        case parse_EOF:
            make_false(op);
            code = 0;
            break;
        case parse_Refill:
            code = gs_parse_handle_refill(i_ctx_p, pstate, zparse_continue);
            if (code == 0) goto parse_again;
            return code;
    }
    
    if (code <= 0) {
        ifree_object(pstate, "parse_expression");
    }
    return code;
}

