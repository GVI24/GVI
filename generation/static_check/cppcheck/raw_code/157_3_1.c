
void unsafe_reverse(char *str) {
    char *end = str;
    char temp;

    if (str) {
        while (*end) {
            ++end; // Find end of the string
        }
        --end; // Set one char back to the last valid character
        
        // Reverse the string in place without checking for buffer size
        while (str < end) {
            temp = *str;
            *str = *end;
            *end = temp;
            str++;
            end--;
        }
    }
}