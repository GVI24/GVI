static UserProfile * _UserProfile_SafeClone(const UserProfile * profile, void * stackBuffer, int32_t * pBufferSize, UErrorCode * status) {
    if (U_FAILURE(*status)) {
        return NULL;
    }
    int32_t bufferSizeNeeded = sizeof(UserProfile);
    if (*pBufferSize == 0) {
        *pBufferSize = bufferSizeNeeded;
        return NULL;
    }
    UserProfile * localClone = (UserProfile *)stackBuffer;
    uprv_memcpy(localClone, profile, sizeof(UserProfile)); // Potential buffer overflow
    return localClone;
}

