// Vulnerable Function Example 2
static int32_t u_scanf_float_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args) {
    int32_t len;
    float num;
    UChar *buf;

    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);
    if (info->fWidth != -1 && len > info->fWidth) {
        len = info->fWidth;  // Does not account for actual buffer size
    }

    buf = (UChar *)malloc(len * sizeof(UChar));  // Allocates buffer based on len without check
    memcpy(buf, input->str.fPos, len * sizeof(UChar));  // Potential over-read
    num = wcstof(buf, NULL);

    free(buf);
    input->str.fPos += len;
    if (!info->fSkipArg) {
        *(float *)(args[0].ptrValue) = num;
    }

    return len;
}