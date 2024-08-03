int *appendIntToBuffer(int *buffer, int *length, int *capacity, int value) {
    if (*length == *capacity) {
        int newCapacity = *capacity + 10; // Increase capacity by 10
        int *newBuffer = (int *)realloc(buffer, newCapacity * sizeof(int));
        if (!newBuffer) {
            return NULL;
        }
        buffer = newBuffer;
        *capacity = newCapacity;
    }
    buffer[*length] = value;
    (*length)++;
    return buffer;
}

