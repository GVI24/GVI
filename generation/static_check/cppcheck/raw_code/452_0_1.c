static VALUE cState_buffer_set(VALUE self, VALUE buffer) {
    GET_STATE(self);
    Check_Type(buffer, T_STRING);
    long buf_len = RSTRING_LEN(buffer);

    if (buf_len > 0) {
        if (state->buffer)
            ruby_xfree(state->buffer);
        state->buffer = ALLOC_N(char, buf_len + 1);
        memcpy(state->buffer, RSTRING_PTR(buffer), buf_len);
        state->buffer[buf_len] = '\0';
        state->buffer_len = buf_len;
    } else {
        if (state->buffer) {
            ruby_xfree(state->buffer);
            state->buffer = NULL;  // Correct handling of the memory
        }
        state->buffer_len = 0;
    }
    return Qnil;
}

