zend_object_iterator *config_file_iterator(zend_class_entry *ce, zval *object TSRMLS_DC) {
    config_iterator *iterator;
    config_object *config_obj;
    
    config_obj = (config_object *)zend_object_store_get_object(object TSRMLS_CC);
    iterator = config_object_to_iterator(config_obj);
    if (iterator->intern.data == NULL) {
        iterator->intern.data = object;
        iterator->intern.funcs = &config_iterator_funcs;
    }

    zval_add_ref(&object);
    return (zend_object_iterator *)iterator;
}