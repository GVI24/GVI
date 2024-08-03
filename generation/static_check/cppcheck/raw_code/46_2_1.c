static int u_scanf_date_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args) {
    int32_t len;
    UChar dateString[256];
    UDateFormat *dateFormat;
    UDate date;
    
    u_scanf_skip_leading_ws(input, info->fPadChar);
    len = (int32_t)(input->str.fLimit - input->str.fPos);
    if(info->fWidth != -1 && info->fWidth < 256) {
        len = ufmt_min(len, info->fWidth);
    }
    dateFormat = u_locbund_getDateFormat(&input->str.fBundle);
    if(!dateFormat) return 0;

    u_strncpy(dateString, input->str.fPos, len);
    dateString[len] = 0; // Null-terminate the string
    date = udat_parse(dateFormat, dateString, len, NULL);

    if(!info->fSkipArg) {
        *(UDate *)(args->ptrValue) = date;
    }

    input->str.fPos += len;
    return len;
}

