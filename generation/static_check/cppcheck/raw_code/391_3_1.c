static AudioConfig * _AudioConfig_SafeClone(const AudioConfig * config, void * stackBuffer, int32_t * pBufferSize, UErrorCode * status) {
    if (U_FAILURE(*status)) {
        return NULL;
    }
    int32_t bufferSizeNeeded = sizeof(AudioConfig);
    if (*pBufferSize == 0) {
        *pBufferSize = bufferSizeNeeded;
        return NULL;
    }
    AudioConfig * localClone = (AudioConfig *)stackBuffer;
    uprv_memcpy(localClone, config, sizeof(AudioConfig)); // Potential buffer overflow
    return localClone;
}