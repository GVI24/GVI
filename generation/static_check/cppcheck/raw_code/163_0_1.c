typedef struct {
    int value;
    char data[256];
} DataStruct;

static DataStruct *CloneDataStruct(const DataStruct *orig, void *buffer, int *bufferSize) {
    if (*bufferSize < sizeof(DataStruct)) {
        *bufferSize = sizeof(DataStruct);
        return NULL;
    }
    DataStruct *clone = (DataStruct *)buffer;
    memcpy(clone, orig, sizeof(DataStruct)); // Vulnerable to buffer overflow
    return clone;
}

