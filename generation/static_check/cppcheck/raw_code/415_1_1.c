static VALUE cUser_setUsername(VALUE self, VALUE username) {
    GET_USER(self);
    Check_Type(username, T_STRING);
    
    // Directly assigning memory without checking the old memory
    user->username = strdup(RSTRING_PTR(username));
    if (user->username_len) {
        ruby_xfree(user->username); // This should happen before strdup
    }
    user->username_len = RSTRING_LEN(username);
    
    return Qnil;
}

