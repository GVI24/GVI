static VALUE cState_description_set(VALUE self, VALUE description) {
    char *temp;
    GET_STATE(self);
    Check_Type(description, T_STRING);
    long desc_len = RSTRING_LEN(description);

    if (desc_len == 0) {
        if (state->description) {
            ruby_xfree(state->description);
            state->description = NULL;  // Correct handling of the memory
        }
        state->description_len = 0;
    } else {
        temp = strdup(RSTRING_PTR(description));
        if (state->description)
            ruby_xfree(state->description);
        state->description = temp;
        state->description_len = desc_len;
    }
    return Qnil;
}

