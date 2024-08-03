static int32_t u_scanf_custom_number_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args) {
    int32_t len;
    double num;
    UChar pattern[256];
    UNumberFormat *format;
    int32_t parsePos = 0;
    UErrorCode status = U_ZERO_ERROR;

    if(info->fWidth >= 256) {
        // Potential overflow if info->fWidth is too large
        return -1;
    }

    u_scanf_skip_leading_ws(input, info->fPadChar);
    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);
    format = unum_open(UNUM_IGNORE, pattern, -1, NULL, NULL, &status);
    if(U_FAILURE(status)) return 0;

    num = unum_parseDouble(format, input->str.fPos, len, &parsePos, &status);
    unum_close(format);

    if(U_SUCCESS(status)) {
        *(double *)(args->ptrValue) = num;
    } else {
        return 0;
    }

    input->str.fPos += parsePos;
    return parsePos;
}