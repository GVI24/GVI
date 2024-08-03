static int32_t u_scanf_int_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args) {
    int32_t len;
    int32_t num;
    UNumberFormat *format;
    int32_t parsePos = 0;
    UErrorCode status = U_ZERO_ERROR;

    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);

    format = u_locbund_getNumberFormat(&input->str.fBundle, UNUM_DECIMAL);
    if (format == NULL) return 0;

    num = unum_parse(format, input->str.fPos, len, &parsePos, &status);
    if (status == U_ZERO_ERROR) {
        *(int32_t *)(args->ptrValue) = num;
    }

    input->str.fPos += parsePos;
    return parsePos;
}

