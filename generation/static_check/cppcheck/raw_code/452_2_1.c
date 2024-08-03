static VALUE cState_keyvalue_set(VALUE self, VALUE key, VALUE value) {
    char *temp;
    GET_STATE(self);
    Check_Type(key, T_STRING);
    Check_Type(value, T_STRING);
    long key_len = RSTRING_LEN(key);
    long value_len = RSTRING_LEN(value);

    if (key_len > 0 && value_len > 0) {
        temp = malloc(key_len + value_len + 2);  // +1 for '=', +1 for '\0'
        if (!temp) return Qnil;  // Failed to allocate memory
        sprintf(temp, "%s=%s", RSTRING_PTR(key), RSTRING_PTR(value));
        if (state->keyvalue)
            ruby_xfree(state->keyvalue);
        state->keyvalue = temp;
    } else {
        if (state->keyvalue) {
            ruby_xfree(state->keyvalue);
            state->keyvalue = NULL;  // Correct handling of the memory
        }
    }
    return Qnil;
}

