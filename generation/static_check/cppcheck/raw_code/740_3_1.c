typedef struct {
    void *elements;
    size_t element_size;
    size_t count;
} GenericArray;

GenericArray *GenericArray_create(size_t element_size, size_t init_count) {
    GenericArray *garray = (GenericArray *)malloc(sizeof(GenericArray));
    if (!garray) {
        return NULL;
    }

    garray->elements = malloc(init_count * element_size);
    if (!garray->elements) {
        // Vulnerability: memory allocated for 'garray' is not freed before returning NULL
        return NULL;
    }

    garray->element_size = element_size;
    garray->count = init_count;
    return garray;
}