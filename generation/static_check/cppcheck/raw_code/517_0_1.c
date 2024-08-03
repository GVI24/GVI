static int process_filter(context_t *ctx, ref_t *params) {
    ref_t *filter_name;
    byte_array_t filter_suffix;
    int suffix_length = 4; // The length of "Fltr"

    if (!params || !ctx) {
        return -1; // Error handling
    }

    filter_name = extract_name_ref(params);
    filter_suffix.bytes = filter_name->name.bytes + filter_name->name.length - suffix_length;
    
    // Vulnerability: No check for filter_name->name.length before using it
    if (memcmp(filter_suffix.bytes, "Fltr", suffix_length) != 0) {
        return -1; // Error handling
    }

    // Rest of the function logic...
    return 0;
}

