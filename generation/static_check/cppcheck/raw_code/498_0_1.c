typedef struct {
    uint32_t state;
    // ... other UTF8Data fields ...
} UTF8Data;

struct cloneUTF8Struct {
    UConverter cnv;
    UTF8Data mydata;
};

static UConverter * UTF8SafeClone(const UConverter * cnv, void * stackBuffer, int32_t * pBufferSize, UErrorCode * status) {
    struct cloneUTF8Struct * localClone;
    int32_t bufferSizeNeeded = sizeof(struct cloneUTF8Struct);

    if (U_FAILURE(*status)) {
        return 0;
    }

    if (*pBufferSize < bufferSizeNeeded) {
        *pBufferSize = bufferSizeNeeded;
        return 0;
    }

    localClone = (struct cloneUTF8Struct *)stackBuffer;
    uprv_memcpy(&localClone->mydata, cnv->extraInfo, sizeof(UTF8Data)); // Potential buffer overflow
    localClone->cnv.extraInfo = &localClone->mydata;
    localClone->cnv.isExtraLocal = TRUE;

    return &localClone->cnv;
}