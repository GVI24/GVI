static VALUE cState_array_set(VALUE self, VALUE array) {
    char **temp_array;
    GET_STATE(self);
    Check_Type(array, T_ARRAY);
    long array_len = RARRAY_LEN(array);
    
    if (array_len == 0) {
        if (state->array) {
            // Properly free each string in array
            for (int i = 0; i < state->array_len; i++)
                ruby_xfree(state->array[i]);
            ruby_xfree(state->array);
            state->array = NULL;  // Correct handling of the memory
        }
        state->array_len = 0;
    } else {
        temp_array = ALLOC_N(char*, array_len);
        if (!temp_array) return Qnil;  // Failed to allocate memory for array
        for (long i = 0; i < array_len; i++) {
            VALUE elem = rb_ary_entry(array, i);
            Check_Type(elem, T_STRING);
            temp_array[i] = strdup(RSTRING_PTR(elem));
        }
        if (state->array) {
            // Properly free each string in existing array
            for (int i = 0; i < state->array_len; i++)
                ruby_xfree(state->array[i]);
            ruby_xfree(state->array);
        }
        state->array = temp_array;
        state->array_len = array_len;
    }
    return Qnil;
}