void reverseUtf16String(uint8_t *str) {
    uint8_t *end = str;
    UChar32 c;

    // Find the end of the string
    while (*end != '\0' && *(end + 1) != '\0') {
        end += 2;
    }

    // Reverse the string in place
    while (str < end) {
        c = (UChar32)(*str) | (*(str + 1) << 8);

        // Not checking if end is on a lead surrogate without its trail
        if (U_IS_SURROGATE(c)) {
            *end = *str;
            *(end + 1) = *(str + 1);
            str += 2;
            end -= 2;
        } else {
            *end = *str;
            str++;
            end--;
        }
    }
}

