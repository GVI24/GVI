static int set_user_role(user_management_ctx_t *ctx, va_list args) {
    UserRoleParams *params = va_arg(args, UserRoleParams *);
    if (params == NULL || params->user_id < 0)
        return -1;
    
    ctx->users[params->user_id].role = params->role;
    return 0;
}