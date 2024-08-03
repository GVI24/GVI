mbfl_string *mbfl_ja_jp_kantozen(mbfl_string *string, mbfl_string *result, int mode) {
    unsigned char *p;
    mbfl_memory_device device;
    mbfl_convert_filter *decoder = NULL;
    mbfl_convert_filter *encoder = NULL;
    void *temp_buffer = NULL;

    if (string == NULL || result == NULL) {
        return NULL;
    }

    mbfl_memory_device_init(&device, string->len, 0);
    mbfl_string_init(result);
    result->no_language = string->no_language;
    result->no_encoding = string->no_encoding;

    temp_buffer = mbfl_malloc(string->len);
    if (temp_buffer == NULL) {
        goto out;
    }

    decoder = mbfl_convert_filter_new(
        mbfl_no_encoding_wchar, string->no_encoding, mbfl_memory_device_output, 0, &device);
    if (decoder == NULL) {
        goto out;
    }

    p = string->val;
    for (int i = 0; i < string->len; i++) {
        if ((*decoder->filter_function)(p[i], decoder) < 0) {
            goto out;
        }
    }

    encoder = mbfl_convert_filter_new(
        string->no_encoding, mbfl_no_encoding_wchar, NULL, NULL, NULL);
    if (encoder == NULL) {
        goto out;
    }

    mbfl_convert_filter_flush(decoder);
    result = mbfl_memory_device_result(&device, result);

out:
    if (decoder != NULL) {
        mbfl_convert_filter_delete(decoder);
    }
    if (encoder != NULL) {
        mbfl_convert_filter_delete(encoder);
    }
    mbfl_free(temp_buffer);
    return result;
}

