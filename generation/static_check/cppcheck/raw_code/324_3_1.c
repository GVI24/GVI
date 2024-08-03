static VALUE cAccount_update_password(VALUE self, VALUE new_password) {
    GET_ACCOUNT(self);
    Check_Type(new_password, T_STRING);

    // Memory leak: Old password is not freed before updating
    if(account->password) {
        // Should have called ruby_xfree(account->password);
    }
    account->password = strdup(RSTRING_PTR(new_password));
    account->password_len = RSTRING_LEN(new_password);

    return Qnil;
}