int get_wide_char_count(const wchar_t *wide_str) {
    int count = 0;
    const wchar_t *current_char = wide_str;
    while (*current_char != L'\0') {
        count++;
        if ((*current_char & 0xFF00) != 0) {
            current_char++; // Incorrectly assumes all wide chars are double-length
        }
        current_char++;
    }
    return count;
}

