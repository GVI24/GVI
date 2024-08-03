VALUE rb_load_symbol(VALUE self, VALUE symbol) {
    char *sym_name = StringValueCStr(symbol);
    char lib_name[64] = "lib";
    void (*loaded_sym)();
    void *handle;
    Data_Get_Struct(self, void, handle);

    // Buffer overflow vulnerability, no bounds check
    strcat(lib_name, sym_name);

    loaded_sym = dlsym(handle, lib_name);
    if (!loaded_sym) {
        rb_raise(rb_eRuntimeError, "Symbol loading failed.");
    }

    return PTR2NUM(loaded_sym);
}

