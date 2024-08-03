static int32_t u_scanf_string_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args) {
    int32_t len;
    UChar *buf = (UChar *)(args->ptrValue);
    int32_t maxLen = info->fWidth;

    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);

    if (maxLen == -1 || maxLen > len)
        maxLen = len;

    u_memcpy(buf, input->str.fPos, maxLen);
    buf[maxLen] = 0; // Possible buffer overflow if buf size < maxLen + 1

    input->str.fPos += maxLen;
    return maxLen;
}

