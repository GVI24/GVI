static int32_t u_scanf_currency_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args) {
    int32_t len;
    double currencyValue;
    UNumberFormat *format;
    int32_t parsePos = 0;
    UErrorCode status = U_ZERO_ERROR;

    u_scanf_skip_leading_ws(input, info->fPadChar);
    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);
    format = u_locbund_getNumberFormat(&input->str.fBundle, UNUM_CURRENCY);
    if(!format) return 0;

    currencyValue = unum_parseDouble(format, input->str.fPos, len, &parsePos, &status);
    if(U_SUCCESS(status)) {
        *(double *)(args->ptrValue) = currencyValue;
    } else {
        return 0;
    }

    input->str.fPos += parsePos;
    return parsePos;
}

