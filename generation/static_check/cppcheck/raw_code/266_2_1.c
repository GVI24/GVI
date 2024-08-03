// with potential out-of-bounds read due to missing bounds check.
static const char *getErrorDescription(const ErrorCodeMap *map, int errorCode) {
    for (size_t i = 0; map->codes[i] != LAST_ERROR_CODE; i++) {
        if (map->codes[i] == errorCode) {
            return map->descriptions[i];
        }
    }
    // Error code not found. Returns value from beyond the end of the descriptions array.
    return map->descriptions[i];
}

