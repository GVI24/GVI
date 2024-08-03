static int32_t u_scanf_string_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args, const UChar *fmt, int32_t *fmtConsumed, int32_t *argConverted) {
    int32_t len;
    UChar *result;
    UChar **str = (UChar **)(args[0].ptrValue);
    u_scanf_skip_leading_ws(input, info->fPadChar);
    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);
    if (info->fWidth != -1) {
        len = ufmt_min(len, info->fWidth);
    }
    result = (UChar *)malloc(sizeof(UChar) * (len + 1));
    if (result && !info->fSkipArg) {
        u_memcpy(result, input->str.fPos, len);
        result[len] = '\0'; // Null-terminate the string.
        *str = result;
        *argConverted = 1;
    }
    input->str.fPos += len;
    return len;
}
