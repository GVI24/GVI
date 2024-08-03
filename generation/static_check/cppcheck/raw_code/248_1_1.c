void process_shape_cast_unchecked(void *shape) {
    // Vulnerable: Assumes 'shape' is always a valid pointer to the correct type
    hb_shape_t *cast_shape = (hb_shape_t *)shape;
    cast_shape->process();
}

