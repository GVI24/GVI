static NetworkConfig * _NetworkConfig_SafeClone(const NetworkConfig * config, void * stackBuffer, int32_t * pBufferSize, UErrorCode * status) {
    if (U_FAILURE(*status)) {
        return NULL;
    }
    int32_t bufferSizeNeeded = sizeof(NetworkConfig);
    if (*pBufferSize == 0) {
        *pBufferSize = bufferSizeNeeded;
        return NULL;
    }
    NetworkConfig * localClone = (NetworkConfig *)stackBuffer;
    uprv_memcpy(localClone, config, sizeof(NetworkConfig)); // Potential buffer overflow
    return localClone;
}

