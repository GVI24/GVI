static VALUE cDocument_set_title(VALUE self, VALUE title) {
    GET_DOCUMENT(self);
    Check_Type(title, T_STRING);

    // Memory leak: strdup called without freeing original memory
    user->title = strdup(RSTRING_PTR(title));
    user->title_len = RSTRING_LEN(title);

    return Qnil;
}

