static VALUE cDocument_setTitle(VALUE self, VALUE title) {
    GET_DOCUMENT(self);
    Check_Type(title, T_STRING);
    
    if (document->title) {
        ruby_xfree(document->title); // Freeing the old title
    }
    // Not checking if the allocation was successful
    document->title = strdup(RSTRING_PTR(title));
    if (!document->title) {
        // Handle allocation error
    }
    document->title_len = RSTRING_LEN(title);
    
    return Qnil;
}

