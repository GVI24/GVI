static int32_t u_sprintf_string_handler(const u_printf_stream_handler *handler, void *context, ULocaleBundle *formatBundle, const u_printf_spec_info *info, const ufmt_args *args) {
    int32_t len, written;
    const char *arg = (const char *)(args[0].ptrValue);
    if(arg == NULL) {
        arg = gNullStr;
    }
    // Vulnerability: No check for the arg length
    len = strlen(arg);
    written = handler->write(context, arg, len);
    return written;
}

