// Vulnerable Function Example 3
static int32_t u_scanf_string_handler(UFILE *input, u_scanf_spec_info *info, ufmt_args *args) {
    int32_t len, result = 0;
    UChar *str;

    ufile_fill_uchar_buffer(input);
    len = (int32_t)(input->str.fLimit - input->str.fPos);
    if (info->fWidth == -1 || len < info->fWidth) {
        info->fWidth = len;  // Fails to correctly handle width
    }

    str = (UChar *)malloc((info->fWidth + 1) * sizeof(UChar));  // Allocates space for string
    if (!str) {
        return 0;  // Out of memory
    }

    memcpy(str, input->str.fPos, info->fWidth * sizeof(UChar));  // Potential over-read if width is incorrect
    str[info->fWidth] = '\0';  // Null-terminate the string

    input->str.fPos += info->fWidth;
    if (!info->fSkipArg) {
        *(UChar **)(args[0].ptrValue) = str;
        result = 1;
    } else {
        free(str);
    }

    return result;
}