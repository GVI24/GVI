VALUE rb_get_method(VALUE self, VALUE method_name) {
    char *name = StringValuePtr(method_name);
    void (*method)();
    void *mod_handle;
    Data_Get_Struct(self, void, mod_handle);

    method = dlsym(mod_handle, name);
    if (!method) {
        // Format string vulnerability
        // The name could contain format specifiers that rb_raise interprets
        rb_raise(rb_eRuntimeError, name);
    }

    return PTR2NUM(method);
}