static VALUE cPreferences_set_theme(VALUE self, VALUE theme) {
    GET_PREFERENCES(self);
    Check_Type(theme, T_STRING);

    // Memory leak: Missing free for previous theme setting
    if(preferences->theme) {
        ruby_xfree(preferences->theme);
    }
    preferences->theme = strdup(RSTRING_PTR(theme));

    return Qnil;
}

