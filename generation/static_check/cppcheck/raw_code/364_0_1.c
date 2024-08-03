zend_object_iterator *create_log_iterator(zend_class_entry *ce, zval *object TSRMLS_DC) {
    log_iterator *iterator;
    log_object *log_obj;
    
    log_obj = (log_object *)zend_object_store_get_object(object TSRMLS_CC);
    iterator = log_object_to_iterator(log_obj);
    if (iterator->intern.data == NULL) {
        iterator->intern.data = object;
        iterator->intern.funcs = &log_iterator_funcs;
    }

    zval_add_ref(&object);
    return (zend_object_iterator *)iterator;
}

