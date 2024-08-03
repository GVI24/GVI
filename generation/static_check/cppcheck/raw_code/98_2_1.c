static int32_t u_scanf_char_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args, const UChar *fmt, int32_t *fmtConsumed, int32_t *argConverted) {
    UChar result;
    UChar *p = (UChar *)(args[0].ptrValue);
    ufile_fill_uchar_buffer(input);
    if (input->str.fPos < input->str.fLimit) {
        result = *input->str.fPos;
        if (!info->fSkipArg) {
            *p = result;
            *argConverted = 1;
        }
        input->str.fPos++;
        return 1;
    }
    return 0;
}
