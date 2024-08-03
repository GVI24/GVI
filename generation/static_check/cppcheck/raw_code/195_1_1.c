static int32_t u_printf_float_handler (const u_printf_stream_handler *handler, void *context, ULocaleBundle *formatBundle, const u_printf_spec_info *info, const ufmt_args *args) {
    double num = args[0].doubleValue;
    UChar result[UPRINTF_BUFFER_SIZE];
    int32_t len = UPRINTF_BUFFER_SIZE;
    ufmt_doubleToU(result, &len, num, info->fPrecision == -1 ? 6 : info->fPrecision);
    if (info->fAlt && result[0] != '0' && len < UPRINTF_BUFFER_SIZE - 2) {
        memmove(result + 2, result, len * sizeof(UChar));
        result[0] = '0';
        result[1] = 'x';
        len += 2;
    }
    return handler->pad_and_justify(context, info, result, len);
}

