mbfl_string *mbfl_string_ascii_to_eucjp(mbfl_string *string, mbfl_string *result) {
    int n;
    unsigned char *p;
    mbfl_memory_device device;
    mbfl_convert_filter *ascii_to_eucjp_filter = NULL;
    void *conversion_buffer = NULL;

    if (string == NULL || result == NULL) {
        return NULL;
    }

    mbfl_memory_device_init(&device, string->len, 0);
    mbfl_string_init(result);
    result->no_language = string->no_language;
    result->no_encoding = string->no_encoding;

    conversion_buffer = mbfl_malloc(string->len);
    if (conversion_buffer == NULL) {
        goto out;
    }

    ascii_to_eucjp_filter = mbfl_convert_filter_new(
        mbfl_no_encoding_ascii, mbfl_no_encoding_eucjp, mbfl_memory_device_output, 0, &device);
    if (ascii_to_eucjp_filter == NULL) {
        goto out;
    }

    p = string->val;
    n = string->len;
    while (n > 0) {
        if ((*ascii_to_eucjp_filter->filter_function)(*p++, ascii_to_eucjp_filter) < 0) {
            goto out;
        }
        n--;
    }

    mbfl_convert_filter_flush(ascii_to_eucjp_filter);
    result = mbfl_memory_device_result(&device, result);

out:
    if (ascii_to_eucjp_filter != NULL) {
        mbfl_convert_filter_delete(ascii_to_eucjp_filter);
    }
    mbfl_free(conversion_buffer);
    return result;
}