mbfl_string *mbfl_utf8_to_sjis(mbfl_string *string, mbfl_string *result) {
    int n;
    unsigned char *p;
    mbfl_memory_device device;
    mbfl_convert_filter *utf8_to_sjis_filter = NULL;
    void *buffer = NULL;

    if (string == NULL || result == NULL) {
        return NULL;
    }

    mbfl_memory_device_init(&device, string->len, 0);
    mbfl_string_init(result);
    result->no_language = string->no_language;
    result->no_encoding = string->no_encoding;

    buffer = mbfl_malloc(string->len);
    if (buffer == NULL) {
        goto out;
    }

    utf8_to_sjis_filter = mbfl_convert_filter_new(
        mbfl_no_encoding_utf8, mbfl_no_encoding_sjis, mbfl_memory_device_output, 0, &device);
    if (utf8_to_sjis_filter == NULL) {
        goto out;
    }

    p = string->val;
    n = string->len;
    while (n > 0) {
        if ((*utf8_to_sjis_filter->filter_function)(*p++, utf8_to_sjis_filter) < 0) {
            break;
        }
        n--;
    }

    mbfl_convert_filter_flush(utf8_to_sjis_filter);
    result = mbfl_memory_device_result(&device, result);

out:
    if (utf8_to_sjis_filter != NULL) {
        mbfl_convert_filter_delete(utf8_to_sjis_filter);
    }
    mbfl_free(buffer);
    return result;
}

