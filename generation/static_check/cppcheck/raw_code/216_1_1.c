static VALUE cState_prefix_set(VALUE self, VALUE prefix) {
    unsigned long len;
    GET_STATE(self);
    Check_Type(prefix, T_STRING);
    len = RSTRING_LEN(prefix);
    if (state->prefix) {
        ruby_xfree(state->prefix);
    }
    if (len > 0) {
        state->prefix = strdup(RSTRING_PTR(prefix));
        // No check on strdup and missing memory deallocation when len == 0
        state->prefix_len = len;
    }
    return Qnil;
}

