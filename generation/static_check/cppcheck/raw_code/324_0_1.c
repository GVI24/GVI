static VALUE cUser_set_username(VALUE self, VALUE username) {
    char *temp;
    GET_USER(self);
    Check_Type(username, T_STRING);

    if (user->username) {
        // Memory leak: Not freeing the previously allocated memory
        temp = strdup(RSTRING_PTR(username));
        if(temp) {
            user->username = temp;
        }
    } else {
        user->username = strdup(RSTRING_PTR(username));
    }

    return Qnil;
}

