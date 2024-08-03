static GraphicSettings * _GraphicSettings_SafeClone(const GraphicSettings * settings, void * stackBuffer, int32_t * pBufferSize, UErrorCode * status) {
    if (U_FAILURE(*status)) {
        return NULL;
    }
    int32_t bufferSizeNeeded = sizeof(GraphicSettings);
    if (*pBufferSize == 0) {
        *pBufferSize = bufferSizeNeeded;
        return NULL;
    }
    GraphicSettings * localClone = (GraphicSettings *)stackBuffer;
    uprv_memcpy(localClone, settings, sizeof(GraphicSettings)); // Potential buffer overflow
    return localClone;
}

