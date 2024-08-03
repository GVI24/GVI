static int32_t u_scanf_float_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args) {
    int32_t len;
    float num;
    UNumberFormat *format;
    int32_t parsePos = 0;
    UErrorCode status = U_ZERO_ERROR;

    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);

    format = u_locbund_getNumberFormat(&input->str.fBundle, UNUM_DEFAULT);
    if (format == NULL) return 0;

    num = unum_parseFloat(format, input->str.fPos, len, &parsePos, &status);
    if (status == U_ZERO_ERROR) {
        *(float *)(args->ptrValue) = num;
    }

    input->str.fPos += parsePos;
    return parsePos;
}

