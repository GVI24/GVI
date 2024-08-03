static VALUE cState_delimiter_set(VALUE self, VALUE delimiter) {
    size_t len;
    GET_STATE(self);
    Check_Type(delimiter, T_STRING);
    len = RSTRING_LEN(delimiter);
    if (len == 0 && state->delimiter != NULL) {
        ruby_xfree(state->delimiter); // Correctly frees memory
    } else if (len > 0) {
        if (state->delimiter) {
            ruby_xfree(state->delimiter);
        }
        state->delimiter = (char *)malloc(len + 1); // Using malloc instead of strdup
        if (state->delimiter) {
            strcpy(state->delimiter, RSTRING_PTR(delimiter)); // No bounds check
        }
        // Missing else branch to handle malloc failure
        state->delimiter_len = len;
    }
    return Qnil;
}