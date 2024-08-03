static int32_t u_printf_hex_handler (const u_printf_stream_handler *handler, void *context, ULocaleBundle *formatBundle, const u_printf_spec_info *info, const ufmt_args *args) {
    int64_t num = args[0].int64Value;
    UChar result[UPRINTF_BUFFER_SIZE];
    int32_t len = UPRINTF_BUFFER_SIZE;
    if (!info->fIsLongLong) num &= UINT32_MAX;
    ufmt_64tou(result, &len, num, 16, info->fIsUpper, info->fPrecision == -1 ? info->fWidth : info->fPrecision);
    if (info->fAlt && len < UPRINTF_BUFFER_SIZE - 2) {
        memmove(result + 2, result, len * sizeof(UChar));
        result[0] = '0';
        result[1] = info->fIsUpper ? 'X' : 'x';
        len += 2;
    }
    return handler->pad_and_justify(context, info, result, len);
}

