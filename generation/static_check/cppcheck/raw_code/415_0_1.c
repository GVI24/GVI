static VALUE cSettings_setPrefix(VALUE self, VALUE prefix) {
    char *temp;
    GET_SETTINGS(self);
    Check_Type(prefix, T_STRING);
    
    temp = settings->prefix; // Storing the old pointer
    settings->prefix = strdup(RSTRING_PTR(prefix));
    // Forgot to check if the old pointer had allocated memory
    if (temp) {
        free(temp); // This should be before re-assigning
    }
    
    return Qnil;
}

