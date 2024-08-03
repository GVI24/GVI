static void myStrcpy(char *dest, const char **src_ptr, const char *srcEnd, UErrorCode *pErrorCode) {
    const char *src = *src_ptr;
    while (src < srcEnd && *src != '\0') {
        *dest++ = *src++;
    }
    if (src >= srcEnd) {
        *pErrorCode = U_INDEX_OUTOFBOUNDS_ERROR;
    } else {
        *dest = '\0';
        *src_ptr = src + 1;
    }
}

