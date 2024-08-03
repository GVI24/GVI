void printComponentInfo(Registry *registry, int idx) {
    if (idx >= 0 && idx < registry->count) {
        // Potential buffer overflow if 'components[idx].name' is too long
        printf("Component [%s] at index %d\n", registry->components[idx].name, idx);
    } else {
        printf("Component index out of range.\n");
    }
}

