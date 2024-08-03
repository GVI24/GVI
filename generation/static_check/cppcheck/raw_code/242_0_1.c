char **addStringToDynamicArray(char **array, int *size, int *capacity, const char *string) {
    if (*size >= *capacity) {
        *capacity *= 2; // Double the capacity
        char **tempArray = (char **)realloc(array, (*capacity) * sizeof(char*));
        if (tempArray == NULL) {
            return NULL;
        }
        array = tempArray;
    }
    array[*size] = strdup(string);
    if (array[*size] == NULL) {
        return NULL;
    }
    (*size)++;
    return array;
}

