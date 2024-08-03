static int32_t u_scanf_binary_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args, const UChar *fmt, int32_t *argConverted) {
    int32_t len, skipped;
    uint64_t result;
    void *num = args[0].ptrValue;

    skipped = u_scanf_skip_leading_ws(input, info->fPadChar);
    ufile_fill_uchar_buffer(input);
    
    // Vulnerability: len could become negative
    len = info->fWidth > 0 ? info->fWidth : input->str.fLimit - input->str.fPos;

    result = ufmt_uto64(input->str.fPos, &len, 2);
    input->str.fPos += len;

    if (!info->fSkipArg) {
        if (info->fIsShort) {
            *(int16_t *)num = (int16_t)(result & UINT16_MAX);
        } else if (info->fIsLongLong) {
            *(int64_t *)num = result;
        } else {
            *(int32_t *)num = (int32_t)(result & UINT32_MAX);
        }
    }
    
    *argConverted = !info->fSkipArg;
    return len + skipped;
}

