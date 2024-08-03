static int decode_UTF32_Char(const char **input, const char *inputLimit, UErrorCode *err) {
    if (*input > inputLimit - 4) {
        *err = U_TRUNCATED_CHAR_FOUND;
        return -1;
    }
    int charValue = ((unsigned char)(*input)[0] << 24) | ((unsigned char)(*input)[1] << 16) |
                    ((unsigned char)(*input)[2] << 8) | (unsigned char)(*input)[3];
    *input += 4;
    return charValue;
}

