void array_remove_if(array_container *container, int (*should_remove)(void *element), void (*remove_callback)(void *element)) {
    int i = 0;
    while (i < container->size) {
        if (should_remove(container->array[i])) {
            remove_callback(container->array[i]); // Callback may alter the container
            // The element is removed; we need to shift the rest
            memmove(&container->array[i], &container->array[i + 1], (container->size - i - 1) * sizeof(void *));
            container->size--;
        } else {
            i++;
        }
    }
}

