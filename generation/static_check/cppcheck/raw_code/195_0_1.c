static int32_t u_printf_integer_handler (const u_printf_stream_handler *handler, void *context, ULocaleBundle *formatBundle, const u_printf_spec_info *info, const ufmt_args *args) {
    int64_t num = args[0].int64Value;
    UChar result[UPRINTF_BUFFER_SIZE];
    int32_t len = UPRINTF_BUFFER_SIZE;
    if (info->fIsShort) num &= UINT16_MAX;
    else if (!info->fIsLongLong) num &= UINT32_MAX;
    ufmt_64tou(result, &len, num, 10, FALSE, info->fPrecision == -1 ? info->fWidth : info->fPrecision);
    if (info->fShowPlus && len < UPRINTF_BUFFER_SIZE - 1) {
        memmove(result + 1, result, len * sizeof(UChar));
        result[0] = '+';
        len += 1;
    }
    return handler->pad_and_justify(context, info, result, len);
}

