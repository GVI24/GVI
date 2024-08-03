static void reverse_UTF16BE_string(uint8_t *utf16beString, size_t length, UErrorCode *err) {
    uint8_t *start = utf16beString;
    uint8_t *end = utf16beString + length - 2; // Assumes the length is even

    while (start < end) {
        // Vulnerability: No bounds check for 'end' when length is odd or miscalculated
        UChar32 frontChar = (*start << 8) | *(start + 1);
        UChar32 backChar = (*end << 8) | *(end + 1);

        *start = *end;
        *(start + 1) = *(end + 1);
        *end = frontChar >> 8;
        *(end + 1) = frontChar & 0xFF;

        start += 2;
        end -= 2;
    }

    if (start == end) {
        // Single middle element, no action needed
    } else {
        *err = U_BUFFER_OVERFLOW_ERROR; // Incorrect error code used
    }
}

