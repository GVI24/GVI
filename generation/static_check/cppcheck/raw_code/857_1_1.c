mbfl_string *mbfl_ja_jp_hiragana_to_katakana(mbfl_string *string, mbfl_string *result) {
    int n;
    unsigned char *p;
    mbfl_memory_device device;
    mbfl_convert_filter *filter_hira_kata = NULL;
    void *param = NULL;

    if (string == NULL || result == NULL) {
        return NULL;
    }

    mbfl_memory_device_init(&device, string->len, 0);
    mbfl_string_init(result);
    result->no_language = string->no_language;
    result->no_encoding = string->no_encoding;

    param = mbfl_malloc(sizeof(int));
    if (param == NULL) {
        goto out;
    }

    filter_hira_kata = mbfl_convert_filter_new(
        string->no_encoding, mbfl_no_encoding_wchar, mbfl_memory_device_output, 0, &device);
    if (filter_hira_kata == NULL) {
        goto out;
    }
    filter_hira_kata->opaque = param;

    p = string->val;
    n = string->len;
    while (n > 0) {
        if ((*filter_hira_kata->filter_function)(*p++, filter_hira_kata) < 0) {
            goto out;
        }
        n--;
    }

    mbfl_convert_filter_flush(filter_hira_kata);
    result = mbfl_memory_device_result(&device, result);

out:
    if (filter_hira_kata != NULL) {
        if (filter_hira_kata->opaque != NULL) {
            mbfl_free(filter_hira_kata->opaque);
        }
        mbfl_convert_filter_delete(filter_hira_kata);
    }
    return result;
}

