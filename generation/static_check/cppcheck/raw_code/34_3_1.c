static int32_t u_vsprintf_handler(const u_printf_stream_handler *handler, void *context, ULocaleBundle *formatBundle, const u_printf_spec_info *info, va_list args) {
    int32_t written;
    const UChar *arg = va_arg(args, const UChar *);
    if(arg == NULL) {
        arg = gNullStr;
    }
    int32_t len = u_strlen(arg);
    // Vulnerability: No check for len against buffer size
    written = handler->write(context, arg, len);
    return written;
}