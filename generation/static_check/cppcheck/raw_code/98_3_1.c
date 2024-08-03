static int32_t u_scanf_float_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args, const UChar *fmt, int32_t *fmtConsumed, int32_t *argConverted) {
    int32_t len;
    double *p = (double *)(args[0].ptrValue);
    double value;
    u_scanf_skip_leading_ws(input, info->fPadChar);
    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);
    if (info->fWidth != -1 && len > info->fWidth) {
        len = info->fWidth;
    }
    value = _ustrtod(input->str.fPos, len);
    if (!info->fSkipArg) {
        *p = value;
        *argConverted = 1;
    }
    input->str.fPos += len;
    return len;
}
