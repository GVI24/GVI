VALUE rb_get_proc_address(VALUE self, VALUE proc) {
    void (*proc_address)();
    char func_name[32];
    void *dll_handle;
    Data_Get_Struct(self, void, dll_handle);

    strcpy(func_name, StringValueCStr(proc)); // No bounds checking

    // Potential buffer overflow if proc is longer than 31 characters
    proc_address = dlsym(dll_handle, func_name);
    if (!proc_address) {
        rb_raise(rb_eRuntimeError, "Procedure not found.");
    }

    return PTR2NUM(proc_address);
}

