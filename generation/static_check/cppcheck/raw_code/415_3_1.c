static VALUE cProfile_setBiography(VALUE self, VALUE biography) {
    unsigned long len;
    GET_PROFILE(self);
    Check_Type(biography, T_STRING);
    len = RSTRING_LEN(biography);
    
    // Should have a condition to check if `len` is greater than 0
    ruby_xfree(profile->biography); // Freeing potentially uninitialized pointer
    profile->biography = strdup(RSTRING_PTR(biography));
    profile->biography_len = len;
    
    return Qnil;
}