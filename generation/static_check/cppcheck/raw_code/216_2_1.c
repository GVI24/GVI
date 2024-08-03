static VALUE cState_suffix_set(VALUE self, VALUE suffix) {
    unsigned long len;
    GET_STATE(self);
    Check_Type(suffix, T_STRING);
    len = RSTRING_LEN(suffix);
    if (state->suffix) {
        ruby_xfree(state->suffix); // Free existing memory
    }
    state->suffix = len > 0 ? strdup(RSTRING_PTR(suffix)) : NULL;
    // Missing check if strdup fails due to insufficient memory
    state->suffix_len = len;
    return Qnil;
}

