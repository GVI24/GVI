zend_object_iterator *open_dir_iterator(zend_class_entry *ce, zval *object TSRMLS_DC) {
    dir_iterator *iterator;
    dir_object *dir_obj;
    
    dir_obj = (dir_object *)zend_object_store_get_object(object TSRMLS_CC);
    iterator = dir_object_to_iterator(dir_obj);
    if (iterator->intern.data == NULL) {
        iterator->intern.data = object;
        iterator->intern.funcs = &dir_iterator_funcs;
    }

    zval_add_ref(&object);
    return (zend_object_iterator *)iterator;
}

