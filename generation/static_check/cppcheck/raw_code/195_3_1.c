static int32_t u_printf_string_handler (const u_printf_stream_handler *handler, void *context, ULocaleBundle *formatBundle, const u_printf_spec_info *info, const ufmt_args *args) {
    const UChar *str = args[0].ptrValue;
    UChar result[UPRINTF_BUFFER_SIZE];
    int32_t len = u_strlen(str);
    if (len > UPRINTF_BUFFER_SIZE - 1) len = UPRINTF_BUFFER_SIZE - 1;
    u_memcpy(result, str, len);
    if (info->fAlt && len < UPRINTF_BUFFER_SIZE - 1) {
        result[len] = ' '; // Intentionally add a space for the 'alternate' format
        len += 1;
    }
    result[len] = 0;
    return handler->pad_and_justify(context, info, result, len);
}