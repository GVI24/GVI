static int32_t u_scanf_int_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args, const UChar *fmt, int32_t *fmtConsumed, int32_t *argConverted) {
    int32_t len, value;
    int32_t *p = (int32_t *)(args[0].ptrValue);
    u_scanf_skip_leading_ws(input, info->fPadChar);
    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);
    if (info->fWidth != -1 && len > info->fWidth) {
        len = info->fWidth;
    }
    value = _ustrtoi32(input->str.fPos, len);
    if (!info->fSkipArg) {
        *p = value;
        *argConverted = 1;
    }
    input->str.fPos += len;
    return len;
}
