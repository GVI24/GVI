static VALUE cState_separator_set(VALUE self, VALUE separator) {
    size_t len;
    GET_STATE(self);
    Check_Type(separator, T_STRING);
    len = RSTRING_LEN(separator);
    if (len > 0) {
        if (state->separator) {
            ruby_xfree(state->separator);
        }
        state->separator = strdup(RSTRING_PTR(separator));
        // No NULL check on strdup
        state->separator_len = len;
    } else {
        if (state->separator) {
            ruby_xfree(state->separator);
            state->separator = NULL; // Memory leak if len == 0 and state->separator != NULL
        }
    }
    return Qnil;
}

