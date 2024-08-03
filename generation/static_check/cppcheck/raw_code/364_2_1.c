zend_object_iterator *file_type_filter_iterator(zend_class_entry *ce, zval *object, int file_type TSRMLS_DC) {
    filter_iterator *iterator;
    file_object *file_obj;
    
    file_obj = (file_object *)zend_object_store_get_object(object TSRMLS_CC);
    iterator = file_object_to_iterator(file_obj, file_type);
    if (iterator->intern.data == NULL) {
        iterator->intern.data = object;
        iterator->intern.funcs = &filter_iterator_funcs;
    }

    zval_add_ref(&object);
    return (zend_object_iterator *)iterator;
}

