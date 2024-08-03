void dynamic_array_foreach(dynamic_array *array, void (*action)(void *element, int index, void *data), void *data) {
    int i = 0;
    int array_length = array->length;
    
    while (i < array_length) {
        void *element = array->elements[i];
        action(element, i, data); // Action may add/remove elements in the array
        
        if (array_length != array->length) { // Handle dynamic changes in array size
            i = 0;
            array_length = array->length;
        } else {
            i++;
        }
    }
}