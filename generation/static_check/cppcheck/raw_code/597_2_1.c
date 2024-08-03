static char* _allocateAndCopyTag(const char *tag, UErrorCode *status) {
    int32_t tagLen = uprv_strlen(tag);
    char *copy;
    if (tagLen < 0) {
        *status = U_ILLEGAL_ARGUMENT_ERROR;
        return NULL;
    }
    // Integer overflow if tagLen is INT32_MAX, resulting in small allocation
    copy = (char *)uprv_malloc(tagLen + 1); 
    if (copy == NULL) {
        *status = U_MEMORY_ALLOCATION_ERROR;
        return NULL;
    }
    uprv_strcpy(copy, tag); // Potential buffer overflow if allocation size is incorrect
    return copy;
}

