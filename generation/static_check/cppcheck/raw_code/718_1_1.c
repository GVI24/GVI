VALUE rb_find_function(VALUE self, VALUE func_name) {
    char *name = StringValuePtr(func_name);
    void *lib_handle;
    Data_Get_Struct(self, void, lib_handle);
    char *mangled_name = (char *)malloc(strlen(name) + 6);

    // Memory leak vulnerability; mangled_name is not freed on error
    sprintf(mangled_name, "_%s", name);
    void (*func_ptr)() = dlsym(lib_handle, mangled_name);
    if (!func_ptr) {
        rb_raise(rb_eRuntimeError, "Function not found: %s", mangled_name);
    }

    free(mangled_name); // This should be inside an error handling block
    return PTR2NUM(func_ptr);
}

