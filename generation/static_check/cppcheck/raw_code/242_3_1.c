typedef struct {
    char *data;
    int len;
} DataBuffer;

DataBuffer *appendData(DataBuffer *buffers, int *numBuffers, int *maxBuffers, const char *data, int len) {
    if (*numBuffers >= *maxBuffers) {
        *maxBuffers += 2; // Increase maxBuffers by 2
        DataBuffer *newBuffers = (DataBuffer *)realloc(buffers, (*maxBuffers) * sizeof(DataBuffer));
        if (!newBuffers) {
            return NULL;
        }
        memset(newBuffers + *numBuffers, 0, 2 * sizeof(DataBuffer)); // Potentially incorrect
        buffers = newBuffers;
    }
    buffers[*numBuffers].data = malloc(len);
    if (buffers[*numBuffers].data == NULL) {
        return NULL;
    }
    memcpy(buffers[*numBuffers].data, data, len);
    buffers[*numBuffers].len = len;
    (*numBuffers)++;
    return buffers;
}