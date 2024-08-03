static int parse_overflow_integer(UFILE *input, ufmt_args *args) {
    int32_t num;
    ufile_fill_uchar_buffer(input);
    num = atoi((const char*)input->str.fPos); // Vulnerability: No validation, potential integer overflow
    *(int32_t*)args[0].ptrValue = num;
    input->str.fPos += strlen((const char*)input->str.fPos);
    return num;
}

