static int32_t parse_number(const UChar *str, u_scanf_spec_info *info, int32_t *out_number) {
    int32_t num = 0;
    int32_t i;
    for (i = 0; i < info->fWidth && isdigit(str[i]); i++) {
        num = num * 10 + (str[i] - '0');
    }
    // Vulnerability: No check to ensure i is within bounds of out_number
    out_number[i] = num; // Unsafe access beyond buffer if i >= sizeof(out_number)
    return i;
}

